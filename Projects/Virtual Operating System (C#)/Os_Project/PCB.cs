using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Os_Project
{
    class PCB
    {
        static byte[] Read;                                    // Byte Array To Read From File.

        static byte Pid;                                //Attributes Of A PCB.
        static byte Priority;
        static short Data_size;
        static short Code_size;
        static short[] GPR = new short[16];
        static ushort[] SPR = new ushort[16];
        byte[] Data_Seg= null;
        byte[] Code_Seg= null;
        static string P_filename;
        static short Code_Frames_Needed;
        static short Data_Frames_Needed;
        public const int PTBRc = 10;
        public const int PTBRd = 11;

        #region Loading PCB To Memory

        public PCB(ref byte[] M, ushort FrameForPCB)                    // Initializing PCB.
        {
            Pid = 0;
            Priority = 0;
            Data_size = 0;
            Code_size = 0;
            P_filename = null;


            for (int i = 0; i < 16; i++)
            {
                GPR[i] = 0;
                SPR[i] = 0;
            }

            SPR[10] = 0xFF;
            SPR[11] = 0xFF;
            SPR[12] = 0xFF;
            SPR[13] = 0xFF;
            SPR[14] = 0xFF;

            Read_PCB();                        // Reading PCB From File.
            if (Validate_PCB())             // Validating PCB.
            {
                Get_PCB_Att(Read);                  // Setting PCB Attributes.
                PCB_to_Byte(ref M, FrameForPCB);        // Putting PCB To Memory.
            }

            else
            {
                M[FrameForPCB / 128] = 0;
                Console.WriteLine("Invalid PCB !!!");
            }
        }

        public static bool Validate_PCB()               // Function To Validate A PCB.
        {
            int i;

            if (Read[0] < 0 || Read[0] > 0x31)                // Validating Priority.
            {
                return false;
            }

            else if (Read[2] == 1)                  
            {
                Data_size = Memory.Join(Read[3], Read[4]);          // Validating And Storing Code And Data Sizes.

                i = Data_size + 5;

                if (Read[i] == 2)
                {
                    Code_size = Memory.Join(Read[i + 1], Read[i + 2]);
                    return (Code_size <= 0 || (i + 2 + Code_size) != Read.Length -1 ) ? false : true;
                }

                return true;
            }

            else if (Read[2] == 2)
            {
                Code_size = Memory.Join(Read[3], Read[4]);

                if (Code_size <= 0) return false;

                i = Code_size + 5;

                if (Read[i] == 1 || i < Read.Length-1)
                {
                    Data_size = Memory.Join(Read[i + 1], Read[i + 2]);
                    return (Data_size <= 0 || (i + 2 + Data_size) != Read.Length-1) ? false : true;
                }

                return true;
            }

            return true;
        }

        public void Get_PCB_Att(byte[] File)                // Function To Get PCB Attributes From File.
        {
            int i, j;
            Priority = File[0];
            Pid = File[1];

            if (File[2] == 1)                       // Copying Data And Code Segment.
            {
                Data_Seg = new byte[Data_size];
                for (i = 5,j = 0; j < Data_size; i++,j++)
                {
                    Data_Seg[j] = File[i];
                }

                if (File[i] == 2)
                {
                    Code_Seg = new byte[Code_size];
                    for (i = i + 3, j = 0; j < Code_size; i++, j++)
                    {
                        Code_Seg[j] = File[i];
                    }
                }
            }

            else if (File[2] == 2)
            {
                Code_Seg = new byte[Code_size];
                for (i = 5, j = 0; j < Code_size; i++, j++)
                {
                    Code_Seg[j] = File[i];
                }

                if (File[i] == 1)
                {
                    Data_Seg = new byte[Data_size];
                    for (i = i + 3, j = 0; j < Data_size; i++, j++)
                    {
                        Data_Seg[j] = File[i];
                    }
                }
            }

            Data_Frames_Needed = (short)Math.Ceiling((double)((float)Data_size / (float)128));          // Calculating Frames Needed For Code And Data Seg.
            Code_Frames_Needed = (short)Math.Ceiling((double)((float)Code_size / (float)128));
        }

        public void PCB_to_Byte(ref byte[] Mem, ushort index)               // Function To Put PCB Attributes To Virtual Mem.
        {
            Mem[index++] = Priority;
            Mem[index++] = Pid;
            Mem[index++] = Memory.Break(Data_size)[0];
            Mem[index++] = Memory.Break(Data_size)[1];
            Mem[index++] = Memory.Break(Code_size)[0];
            Mem[index++] = Memory.Break(Code_size)[1];
            Mem[index++] = Memory.Break((short)P_filename.GetHashCode())[0];                // Storing HashCode Of Process File Name.
            Mem[index++] = Memory.Break((short)P_filename.GetHashCode())[1];
            
            SPR[PTBRc] = Memory.Fr_Frame(Memory.Get_PT_Free_Frame(8,128,Code_Frames_Needed));         // Getting Multiple Free Page In Kernel Needed To Store Code Page Table.

            SPR[PTBRd] = Memory.Fr_Frame(Memory.Get_PT_Free_Frame(8, 128, Data_Frames_Needed));        // Getting Multiple Free Page In Kernel Needed To Store Data Page Table.

            Set_Stack_Val(Memory.Fr_Frame(Memory.Get_Free_Frame(129,511)));             // Setting Stack Values By Finding A Free Page In User Memory.

            Segment_Allocation(ref Mem, 1);                     // Putting Data Seg To User Memory.
            Segment_Allocation(ref Mem, 2);                     // Putting Code Seg To User Memory.

            Reg_to_Byte(GPR, ref Mem,ref index);                // Storing General Purpose Reg To Memory.

            Reg_to_Byte(SPR, ref Mem, ref index);                // Storing Special Purpose Reg To Memory.

            Mem[index++] = Memory.Break(Code_Frames_Needed)[0];
            Mem[index++] = Memory.Break(Code_Frames_Needed)[1];

            Mem[index++] = Memory.Break(Data_Frames_Needed)[0];
            Mem[index++] = Memory.Break(Data_Frames_Needed)[1];
        
        }

        void Reg_to_Byte(ushort[] Reg, ref byte[] RB, ref ushort index)          // Function To Store Special Purpose Reg To Memory.
        {
            for (int i = 0; i < 16; i++,index+=2)
            {
                RB[index] = Memory.Break(Reg[i])[0];
                RB[index + 1] = Memory.Break(Reg[i])[1];
            }
        }

        void Reg_to_Byte(short[] Reg, ref byte[] RB, ref ushort index)          // Function To Store General Purpose Reg To Memory.
        {
            for (int i = 0; i < 16; i++, index += 2)
            {
                RB[index] = Memory.Break((short)Reg[i])[0];
                RB[index + 1] = Memory.Break((short)Reg[i])[1];
            }
        }

        #endregion

        #region Getting And Writing File

        public static void Read_PCB()    // Constructor of Memory Class
        {

        GetFile:   //To Read File
            Console.Write("Enter File Name Having Instructions Or 0 To go Back: ");
            P_filename = Console.ReadLine();
            Console.Clear();

            try              //Read the file from Desktop And Checks If The Filename Is Correct.
            {               
                Read = File.ReadAllBytes(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\" + P_filename);
            }
            catch (Exception e)      //If file doesnt exist
            {
                Console.WriteLine(e.Message);
                goto GetFile;
            }
        }

        public static void Write_Dump(byte[] Mem,ushort PCB_Start)
        {
            StreamWriter Write = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\" + P_filename + "_DUMP.txt",false);

            Write.Write(Write.NewLine + "\t\t\t\t*****PROCESS DUMP*****");
            Write.Write(Write.NewLine + Write.NewLine + Write.NewLine + "Process File Name: " + P_filename);
            Write.Write(Write.NewLine + "Priority: " + Priority.ToString("X"));
            Write.Write(Write.NewLine + "Data Segment Size: " + Data_size + " Bytes");
            Write.Write(Write.NewLine + "Code Segment Size: " + Code_size + " Bytes");
            Write.Write(Write.NewLine + "Total Process Size: " + Read.Length + " Bytes");
            Write.Write(Write.NewLine + Write.NewLine + "PCB.... ");

            Write.Write(Mem[PCB_Start + 0].ToString("X") + " ");
            Write.Write(Mem[PCB_Start+ 1].ToString("X") + " ");


            for (SPR[12] = 2; SPR[12] < 8; SPR[12]+=2)
            {
                Write.Write(Memory.Join(Mem[PCB_Start + SPR[12]], Mem[PCB_Start + SPR[12]+1]).ToString("X") + " ");
            }

            Write.Write(Write.NewLine + "Stack.... ");

            for (SPR[12] = SPR[6]; SPR[12] < SPR[7]; SPR[12] += 2)
            {
                Write.Write(Memory.Join(Mem[PCB_Start + SPR[12]], Mem[PCB_Start + SPR[12] + 1]).ToString("X") + " ");
            }

            Write.Write(Write.NewLine + "GPRs.... ");

            for (SPR[12] = 8; SPR[12] < 40; SPR[12]+=2)
            {
                Write.Write(Memory.Join(Mem[PCB_Start + SPR[12]], Mem[PCB_Start + SPR[12] + 1]).ToString("X") + " ");
            }

            Write.Write(Write.NewLine + "SPRs.... ");

            for (SPR[12] = 40; SPR[12] < 72; SPR[12]+=2)
            {
                Write.Write(Memory.Join(Mem[PCB_Start + SPR[12]], Mem[PCB_Start + SPR[12]+1]).ToString("X") + " ");
            }
            Write.Write(Write.NewLine + Write.NewLine + "Data Segment....  ");

            for (SPR[12] = 0; SPR[12] < Data_Frames_Needed; SPR[12]++)
            {
                for (SPR[13] = 0; SPR[13] < Data_size; SPR[13]++)
                {
                    Write.Write(Mem[Memory.Fr_Frame(Memory.Join(Mem[SPR[PTBRd] + SPR[12]], Mem[SPR[PTBRd] + SPR[12]+1])) + SPR[13]].ToString("X") + " ");
                }
            }

            Write.Write(Write.NewLine + Write.NewLine + "Code Segment....  ");

            for (SPR[12] = 0; SPR[12] < Code_Frames_Needed; SPR[12]++)
            {
                for (SPR[13] = 0; SPR[13] < Code_size; SPR[13]++)
                {
                    Write.Write(Mem[Memory.Fr_Frame(Memory.Join(Mem[SPR[PTBRc] + SPR[12]], Mem[SPR[PTBRc] + SPR[12] + 1])) + SPR[13]].ToString("X") + " ");
                }
            }

                Write.Close();
        }

        #endregion

        #region Setting And Loading Registers
        
        public void Set_Stack_Val(ushort Base)      //Function to set stacks's base , limit and count
        {
            ushort Limit = (ushort)(Base + (ushort)50);
            SPR[6] = Base;
            SPR[7] = Limit;
            SPR[8] = SPR[6];
        }

        public void Set_Code_Val(ushort Base, ushort Limit)     //Function to set stacks's base , limit and count
        {
            SPR[3] = Base;
            SPR[4] = Limit;
            SPR[5] = SPR[3];
        }

        public void Set_Data_Val(ushort Base, ushort Limit)     //Function to set stacks's base , limit and count
        {
            SPR[1] = Base;
            SPR[2] = Limit;
        }
        
        #endregion

        #region Generating PTBRs And Copying Segments To Mem

        void Segment_Allocation(ref byte[] Mem, int Seg_no)         // Function To Put Data And Code Segment In User Memory.
        {

            ushort Prev = 0;
            ushort k;

            if (Seg_no == 1)
            {
                for (int i = 1, j = 0; i <= Data_Frames_Needed; i++, j += 2)        // Finds Free Frames Needed By Data Seg To Store In User Memory.
                {
                    SPR[14] = (ushort)Memory.Get_Free_Frame(129, 511);              // Finds Free Frame.           
                    Mem[SPR[PTBRd] + j] = Memory.Break((short)(SPR[14]))[0];
                    Mem[SPR[PTBRd] + (j + 1)] = Memory.Break((short)(SPR[14]))[1];
                    SPR[14] = Memory.Fr_Frame((short)SPR[14]);

                    for (k = Prev; k < Data_size; k++)                          // Storing Data Seg To Free Frames.
                    {
                        Mem[SPR[14]++] = Data_Seg[k];
                    }

                    Prev = k;
                }

            }

            else if (Seg_no == 2)
            {
                for (int i = 1, j = 0; i <= Code_Frames_Needed; i++, j += 2)                // Finds Free Pages Needed By Code Seg To Store In User Memory.
                {
                    SPR[14] = (ushort)Memory.Get_Free_Frame(129, 511);
                    Mem[SPR[PTBRc] + j] = Memory.Break((short)(SPR[14]))[0];
                    Mem[SPR[PTBRc] + (j + 1)] = Memory.Break((short)(SPR[14]))[1];
                    SPR[14] = Memory.Fr_Frame((short)SPR[14]);

                    for (k = Prev; k < Code_size; k++)                          // Storing Code Seg To Free Frames In Memory.
                    {
                        Mem[SPR[14]++] = Code_Seg[k];
                    }

                    Prev = k;
                }
            }

            ushort Code_Start=Memory.Fr_Frame((Memory.Join(Mem[SPR[PTBRc]],Mem[SPR[PTBRc]+1])));           // Storing Start Of Code And Data Segments. 
            ushort Data_Start = Memory.Fr_Frame((Memory.Join(Mem[SPR[PTBRd]], Mem[SPR[PTBRd] + 1])));

            Set_Code_Val(Code_Start, (ushort)(Code_Start + (Code_Frames_Needed * 128)));                        // Setting And Checking Code And Data Seg Values.
            Set_Data_Val(Data_Start, (ushort)(Data_Start + (Data_Frames_Needed * 128)));
        }
        #endregion

    }
}
