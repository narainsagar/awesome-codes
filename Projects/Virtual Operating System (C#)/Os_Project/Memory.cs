using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

                        /* This Memory Is Paged in 512 Pages of 128bytes.
                         * It Contains Kernel From 0 To 128 Pages, else is User Memory.
                         * The Page Tables Are Stored in Multiple Contiguous Page Tables In Kernel.
                         */



namespace Os_Project
{
    class Memory : Registers           //Class of Memory 
    {
        static byte[] Mem = new byte[64 * 1024];  // Initialization of Memory

        short Running_queue_head;               // Queue Heads And tails.
        short Running_queue_tail;
        short Ready1_queue_head;
        short Ready1_queue_tail;
        short Ready2_queue_head;
        short Ready2_queue_tail;

        ushort PCB_Start;

        public int Clock_Cycle;                        
        
        public Memory()
        {
            Clock_Cycle = 8;                        // Setting Clock Cycles.
            Free_Frames_Table_init();                 // Initializing Free Page Table.
            Queue_Init();                           // Initializing Queues.           
        }

        public void Generate_PCB()                     // Function To Generate A New PCB.
        {
            PCB_Start = Fr_Frame(Get_Free_Frame(8, 128));       // Finds A Free Frame To Store The New PCB.

            new PCB(ref Mem, PCB_Start);          // Reads File And Stores PCB To Memory.

                if (Mem[PCB_Start] >= 0 && Mem[PCB_Start] <= 0xF)        // Checks Priority And Enqueues PCB To Respective Queue.
                {
                    Enqueue(ref Ready1_queue_tail, PCB_Start);          // Enqueues To Ready 1 Queue.
                }
                else
                    Enqueue(ref Ready2_queue_tail, PCB_Start);          // Enqueues To Ready 2 Queue.


        }

        #region Free Frame Table                              

        public static ushort Fr_Frame(short FrameNo)            // Function To Convert Frame No To Memory Address.
        {
            return (ushort)(FrameNo * 128);
        }

        void Free_Frames_Table_init()                     // Function To Initialize Free Frames Table.
        {
            for (int i = 0; i < 8; i++)                 // Starting 7 Pages Are Occupied Because Of Free Page Table And Queues.
            {
                Mem[i] = 1;
            }

            for (int i = 8; i < 512; i++)
            {
                Mem[i] = 0;
            }
        }
        public void Show_FreeFrameList()
        {
            Console.WriteLine("\tFree Kernel Frames\n");
            for (int i = 8; i < 128; i++)
            {
                if (Mem[i] == 0)
                    Console.Write("[" + i + "] ");
            }

            Console.Write("\n\tFree User Space Frames\n\n");
            for (int i = 128; i < 512; i++)
            {
                if (Mem[i] == 0)
                    Console.Write("[" + i+"] ");
            }
        }
        public void Show_FreeFrameNumber()
        {
            int k = 0, u = 0;
            for (int i = 8; i < 128; i++)
            {
                if (Mem[i] == 0)
                    k++;
            }
            Console.WriteLine("\tFree Kernel Frames = "+(k+8));
            for (int i = 128; i < 512; i++)
            {
                if (Mem[i] == 0)
                    u++;
            }
            Console.WriteLine("\tFree User Frames   = " + u);
        }


        public void Show_UsedFrameList()
        {
            Console.WriteLine("\tUsed Kernel Frames\n");
            for (int i = 8; i < 128; i++)
            {
                if(Mem[i] != 0)
                Console.WriteLine("\t"+ "Frame # " + i);
            }

            Console.WriteLine("\n\tUsed User Space Frames\n");
            for (int i = 128; i < 512; i++)
            {
                if (Mem[i] != 0)
                    Console.WriteLine("\t" + "Frame # " + i );
            }
        }

        #endregion

        #region Queues

        void Queue_Init()           // Initializing Queues. 
        {
            Running_queue_head = (short)Fr_Frame(5);
            Running_queue_tail = (short)Fr_Frame(5);
            Ready1_queue_head = (short)Fr_Frame(6);
            Ready1_queue_tail = (short)Fr_Frame(6);
            Ready2_queue_head = (short)Fr_Frame(7);
            Ready2_queue_tail = (short)Fr_Frame(7);
        }               

        void Enqueue(ref short Queue_Start, ushort PCB_add)             // Enqueuing To Given Queue.
        {
                    Mem[Queue_Start++] = Break(PCB_add)[0];
                    Mem[Queue_Start++] = Break(PCB_add)[1];
        }      

        ushort Dequeue(ref short Queue_Start)                // Using Selection Sort To Pick The Process With Highest Priority And Dequeues It.
        {
                SP[13] = (ushort)Queue_Start;
                SP[14] = (ushort)Join(Mem[Queue_Start], Mem[Queue_Start + 1]);



                for (SP[12] = (ushort)(SP[13] + 2); Mem[SP[12]] > 0; SP[12] += 2)            // Finds The Process With Highest Priority.
                {
                    if (Mem[Join(Mem[SP[13]], Mem[SP[13] + 1])] > Mem[Join(Mem[SP[12]], Mem[SP[12] + 1])])
                    {
                        SP[13] = SP[12];
                    }
                }

                Mem[Queue_Start] = Mem[SP[13]];
                Mem[Queue_Start + 1] = Mem[SP[13] + 1];

                Mem[SP[13]] = Break(SP[14])[0];
                Mem[SP[13] + 1] = Break(SP[14])[1];

                SP[14] = (ushort)Join(Mem[Queue_Start], Mem[Queue_Start + 1]);

                for (SP[13] = (ushort)Queue_Start; Mem[SP[13]] > 0; SP[13] += 2)           // Reorders The Queue After Dequeuing The Process.
                {
                    SP[12]= (ushort)(SP[13]+2);
                    Mem[SP[13]] = Mem[SP[12]];
                    Mem[SP[13] + 1] = Mem[SP[12] + 1];
                }

                    return SP[14];
            }

        ushort Dequeue_RR(ref short Queue_Start)                // Dequeueing From Ready Queue 2.
        {
            SP[14] = (ushort)Join(Mem[Queue_Start], Mem[Queue_Start + 1]);

            for (SP[13] = (ushort)Queue_Start; Mem[SP[13]] > 0; SP[13] += 2)           // Reorders The Queue After Dequeuing The Process.
            {
                SP[12] = (ushort)(SP[13] + 2);
                Mem[SP[13]] = Mem[SP[12]];
                Mem[SP[13] + 1] = Mem[SP[12] + 1];
            }

            return SP[14];
        }

        void In_Running(ushort PCB_add)                 // Enqueues The Process In Running Queue.
        {
            if (Mem[Running_queue_head] == 0)
            {
                Mem[Running_queue_tail++] = Break(PCB_add)[0];
                Mem[Running_queue_tail++] = Break(PCB_add)[1];
                Load_Reg(ref GP,ref SP,Join(Mem[Running_queue_head],Mem[Running_queue_head+1]));                        // Restoring Register Values To CPU.
            }
            else Console.WriteLine("Running Queue Full !!!");
        }

        ushort Out_Running()                             // Dequeues The Process From Running Queue.
        {
            SP[14] = (ushort)Join(Mem[Running_queue_head], Mem[Running_queue_head + 1]);
            Mem[Running_queue_head]=0;
            Mem[Running_queue_head + 1]=0;
            Running_queue_tail -= 2;
            Save_Reg(ref GP, ref SP, (short)SP[14]);                   // Storing Register Values To PCB.
            PCB.Write_Dump(Mem, SP[14]);
           
            return SP[14];
        }

        ushort Out_Running_WD()                             // Dequeues The Process From Running Queue.
        {
            SP[14] = (ushort)Join(Mem[Running_queue_head], Mem[Running_queue_head + 1]);
            Mem[Running_queue_head] = 0;
            Mem[Running_queue_head + 1] = 0;
            Running_queue_tail -= 2;
            Save_Reg(ref GP, ref SP, (short)SP[14]);                   // Storing Register Values To PCB.

            return SP[14];
        }

        public void Show_Queues()
        {
            Console.WriteLine("\tReady Queue 1\tReady Queue 2\n");

            for (int i = 0; i < 128; i++)
            {
                Console.WriteLine("\t    " + Mem[Ready1_queue_head + i].ToString("X") + "\t\t    " + Mem[Ready2_queue_head + i].ToString("X"));
            }
        }

        #endregion

        #region Load And Save Registers

        public void Load_Reg(ref short[] G, ref ushort[] S, short PS)         // Loading Register Values From PCB To CPU.
        {
            short[] PCB_GP = new short[16];
            ushort[] PCB_SP = new ushort[16];
 
            for (int i = 0,j=8; i < 16; i++,j+=2)
            {
                PCB_GP[i] = Join(Mem[PS + j], Mem[PS + (j + 1)]);
            }

            for (int i = 0, j = 40; i < 16; i++, j += 2)
            {
                PCB_SP[i] = (ushort)Join(Mem[PS + j], Mem[PS + (j + 1)]);
            }

                Array.Copy(PCB_GP, G,16);
                Array.Copy(PCB_SP, S, 16);
        }

        public void Save_Reg(ref short[] G, ref ushort[] S,short PS)     // Saving Register Values From CPU To PCB.
        {
            short[] PCB_GP = new short[16];
            ushort[] PCB_SP = new ushort[16];

            Array.Copy(G, PCB_GP, 16);
            Array.Copy(S, PCB_SP, 16);
            
            for (int i = 0, j = 8; i < 16; i++, j += 2)         // Refreshing GPR And SPR Values To 0.
            {
                Mem[PS + j] = Break(PCB_GP[i])[0];
                Mem[PS + (j+1)] = Break(PCB_GP[i])[1];
            }

            for (int i = 0, j = 40; i < 16; i++, j += 2)
            {
                Mem[PS + j] = Break(PCB_SP[i])[0];
                Mem[PS + (j + 1)] = Break(PCB_SP[i])[1];
            }
        }

        #endregion

        #region Getting Free Frames

        public static short Get_Free_Frame(short Base, short Limit)             // Function To Find Free Frames From Given Base And Limit. 
        {
            short FRF = 513;
            for (short i = Base; i <= Limit; i++)
            {
                if (Mem[i] == 0)
                {
                    Mem[i] = 1;
                    FRF = i;
                    break;
                }
            }

            if (FRF == 513)                 // If No Free Frame Is Found.
            {
                Console.WriteLine("No Free Frame Found !!!");
                return FRF;
            }
            
            else return FRF;
        }

        public static short Get_PT_Free_Frame(short Base, short Limit, short No_of_Fr)            // Finds Specified Number Of Contiguous Free Frames In Given Base And Limit.
        {
            if (No_of_Fr < 64)
                return Get_Free_Frame(Base,Limit);

            else
            {
                short FRF = 513;

                for (short i = Base; i <= Limit; i++)
                {
                    if (Mem[i] == 0)
                    {
                        for (short k = i; k < (No_of_Fr/64) + i; k++)
                        {
                            FRF = k;
                            if (Mem[k] == 1) break;
                        }

                        if (FRF == i + (No_of_Fr/64) - 1)
                        {
                            for (short k = i; k < i + (No_of_Fr/64); k++)
                            {
                                Mem[k] = 1;
                            }
                            return FRF;
                        }
                    }
                }
                return FRF;
            }
        }

        #endregion

        #region Scheduling

        public bool Execute()                  // Executing Multilevel Queues Scheduling.
        {
            byte ins;

       // Check_Queue:

            if (Mem[Running_queue_head] == 0 && Mem[Ready1_queue_head] == 0 && Mem[Ready2_queue_head] == 0)
            {
                Console.WriteLine("\n\t\tNo Process Loaded In Running Queue !!!\n");
                return true;      // All Processes Are Executed Or No Process In Running Queue.
            }

            else if (Mem[Ready1_queue_head] == 0 && Mem[Ready2_queue_head] != 0)                 // If Ready 1 Queue Is Empty.
            {
                In_Running(Dequeue_RR(ref Ready2_queue_head));         // Enqueue A Process From Ready 2 Queue To Running Queue.
                Ready2_queue_tail -= 2;

                for (SP[12] = 0; SP[12] < Clock_Cycle/2; SP[12]++)                   // Runs Round Robin For The Specified No Of Clock Cycles.
                {
                    ins = Read_Mem();

                    if (ins == 0xF3)
                    {
                        Deallocate_PCB(Out_Running());
                        
                        Decode(ins);
                        return true;                                    // Process Ends.
                    }

                    else Decode(ins);
                }

                Enqueue(ref Ready2_queue_tail,Out_Running_WD());

                return true;                                       // Gets Back To Menu.

            }

            else                                    // If Ready 1 Queue Is Not Empty.
            {
                In_Running((ushort)Dequeue(ref Ready1_queue_head));                 // Enqueues A Process From Ready 1 Queue. 
                Ready1_queue_tail -= 2;

                ins = Read_Mem();

                while(ins != 0xF3)                           // Reads Whole Process Until It Is Terminated.
                {
                    Decode(ins);
                    ins = Read_Mem();
                }

                Decode(ins);

                Deallocate_PCB(Out_Running());
                
                return true;
            }
        }

        public void Highest_In_Running()
        {
            if (Mem[Running_queue_head] == 0)
            {
                if (Mem[Ready1_queue_head] == 0)
                {
                    In_Running((ushort)Dequeue(ref Ready2_queue_head));
                    Ready2_queue_tail -= 2;
                }

                else
                {
                    In_Running((ushort)Dequeue(ref Ready1_queue_head));
                    Ready1_queue_tail -= 2;
                }
            }

            else Console.WriteLine("Running Queue Full !!!");
        }

        #endregion

        #region Terminate Process               

        void Deallocate_PCB(ushort PCB_S)               // Function To Deallocate Whole PCB From Memory.
        {
            for (SP[12] = 0; SP[12] <(ushort)Join(Mem[PCB_S + 72], Mem[PCB_S + 73])*2 ; SP[12]+=2)        // Remove All Code Pages.
            {
                Deallocate_Page((short)SP[12], 2);
            }

            for (SP[12] = 0; SP[12] <(ushort)Join(Mem[PCB_S + 74], Mem[PCB_S + 75])*2; SP[12]+=2)        // Remove All Data Pages.
            {
                Deallocate_Page((short)SP[12], 1);
            }

            for (SP[12] = 0; SP[12] < 76; SP[12]++)                 // Remove PCB.
            {
                Mem[PCB_S + SP[12]] = 0;
            }

            for (SP[12] = 0; SP[12] < 50; SP[12]++)            // Emptying Stack.
            {
                Mem[SP[6] + SP[12]] = 0;
            }

            Mem[SP[6] / 128] = 0;                       // Freeing Stack Frame.
            Mem[PCB_S / 128] = 0;                       // Freeing PCB Frame.
        }

        static public void Deallocate_Page(short Pg_No, int Seg_No)          // Function To Deallocate Pages.
        {
            ushort PT_Loc;

            if (Seg_No == 1)
            {
                PT_Loc = (ushort)Fr_Frame(Join(Mem[SP[11] + Pg_No], Mem[SP[11] + Pg_No + 1]));

                Mem[PT_Loc / 128] = 0;          // EMptying Data Page Table From Free Frame List.

                for (SP[13] = PT_Loc; SP[13] < PT_Loc + 128; SP[13]++)            // Emptying Data Segment.
                {
                    Mem[SP[13]] = 0;
                }

                Mem[SP[11] + Pg_No] = 0;            // Removing Frame Num From Data Page Table.
                Mem[SP[11] + Pg_No + 1] = 0;

                Mem[SP[11]/128 + Pg_No] = 0;            // Removing Frame Num From Data Page Table.
                Mem[SP[11]/128 + Pg_No + 1] = 0;
            }

            else if (Seg_No == 2)
            {
                PT_Loc = (ushort)Fr_Frame(Join(Mem[SP[10] + Pg_No], Mem[SP[10] + Pg_No + 1]));

                Mem[PT_Loc / 128] = 0;          // EMptying Code Page Table From Free Frame List.

                for (SP[13] = PT_Loc; SP[13] < PT_Loc + 128; SP[13]++)               // Emptying Code Segment.
                {
                    Mem[SP[13]] = 0;
                }

                Mem[SP[10] + Pg_No] = 0;                // Removing Frame Num From Code Page Table.
                Mem[SP[10] + Pg_No + 1] = 0;

                Mem[SP[10]/128 + Pg_No] = 0;                // Removing Frame Num From Code Page Table.
                Mem[SP[10]/128 + Pg_No + 1] = 0;
            }
        }

        #endregion

        #region Break and Join Byte and Short

        public static byte[] Break(short val)   //Function To Break Short into byte
        {
            byte[] ret = new byte[2];
            ret[0] = (byte)((val & 0xFF00) >> 8);
            ret[1] = (byte)(val & 0x00FF);
            return ret;
        }

        public static byte[] Break(ushort val)   //Function To Break UShort into byte
        {
            byte[] ret = new byte[2];
            ret[0] = (byte)((val & 0xFF00) >> 8);
            ret[1] = (byte)(val & 0x00FF);
            return ret;
        }

       public static short Join(byte a, byte b)  //Function to join two bytes into short
       {
            ushort ret;
            ret = (ushort)(b | (a << 8));
            return (short)ret;
       }

       public static short Join(byte a, byte b, short ret)  //Function to join two bytes into short
       {
           ret = (short)(b | (a << 8));
           return ret;
       }
        #endregion

        #region Read And Write Memory

       public byte Read_Mem()     //Function To Read Memory
       {
           return Mem[SP[5]++];
       }

       public byte Fetch_B()  //Fetch Byte From Memory
       {
           return Mem[SP[5]];
       }

       public byte Fetch_B(ushort val) //Fetch byte From memory
       {
           return Mem[(val + 1)];
       }

       public ushort Fetch_W()   //Fetch Word from Memory
       {
           try
           {
               return (ushort)Join(Mem[SP[5]],Mem[SP[5]+1]);
           }

           catch (Exception)
           {
               Console.WriteLine("\n\tOUT OF MEMORY !!!");
               Console.ReadKey();
               Environment.Exit(0);
             //  Console.WriteLine("\n\tSP{0}\t\t{1}", i + 1, Convert.ToString(SP[i], 16));
               return 0;
           }
       }

       #endregion

        #region Memory Instruction Implementation

       public void MOVL(byte i1, ushort i2) //Instruction of MOVL
       {
           try
           {
               GP[i1] = Mem[SP[1] + i2];
           }
           
           catch (Exception)
           {
               Console.WriteLine("\n\tOUT OF MEMORY !!!");
               Console.ReadKey();
               Environment.Exit(0);
           }
       }

       public void MOVS(byte i1, ushort i2)       //Instruction of MOVS
       {
           try
           {
               Mem[SP[1]+i1] = Break(GP[i2])[0];
               Mem[SP[1]+(i1 + 1)] = Break(GP[i2])[1];
           }

           catch (Exception )
           {
               Console.WriteLine("\n\tOUT OF MEMORY !!!");
               Console.ReadKey();
               Environment.Exit(0);

           }
       }

       #endregion

        #region Stack Operations

       public void PUSH(ushort val) //Function To Push ON Stack
       {
           if (SP[8] < SP[7])
           {
               Mem[SP[8]] = Break(val)[0];
               Mem[SP[8] + 1] = Break(val)[1];
               SP[8] += 2;
           }

           else { Console.WriteLine("\tStack Overflow !!! \n\t Cannot Push !!!");
           Console.ReadKey();
           Environment.Exit(0);
           }
       }

       public void CALL(ushort val)    //Function to Push value into Stack
       {
           if ((SP[3] + val) < SP[4])
           {
               PUSH(SP[5]);
               SP[5] = (ushort)(SP[3] + val);
           }
           else
           {
               Console.WriteLine("\n\tOut Of Code Limit !!!");
               SP[5] += 3;
               Console.ReadKey();
               Environment.Exit(0);
           }
       }

       public void POP(ushort val)    //Function To Pop From Stack
       {
           if (SP[8] > SP[6])
           {
               val = (ushort)Join(Mem[SP[8]], Mem[SP[8] - 1]);
               SP[8] -= 2;
           }

           else
           {
           Console.WriteLine("\tStack Underflow !!! \n\t Cannot Pop !!!");
           Console.ReadKey();
           Environment.Exit(0);
           }
       }

       public void RETURN()  //Function to retrun value from stack
       {
           POP(SP[5]);
       }

       #endregion

        #region DECODING

       public void Decode(byte ins)  //Function To Decode the Given Instruction
       {
           switch (ins)
           {
               #region Register-Register Operations

               case 0x16:       //For Mov Instruction
                  Console.WriteLine("\n\tExecuting MOV....");
                  MOV(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x17:       //For ADD Instruction
                  Console.WriteLine("\n\tExecuting ADD....");
                  ADD(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x18:         //For SUB Instruction
                  Console.WriteLine("\n\tExecuting SUB....");
                  SUB(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x19:         //For MUL Instruction
                  Console.WriteLine("\n\tExecuting MUL....");
                  MUL(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x1A:         //For DIV Instruction
                  Console.WriteLine("\n\tExecuting DIV....");
                  DIV(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x1B:         //For AND Instruction
                  Console.WriteLine("\n\tExecuting AND....");
                  AND(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               case 0x1C:         //For OR Instruction
                  Console.WriteLine("\n\tExecuting OR....");
                  OR(Fetch_B(),Fetch_B(SP[5]));
                  SP[5] += 2;
                  break;

               #endregion

               #region Register - Immediate Operations

               case 0x30:         //For MOVI Instruction
                  Console.WriteLine("\n\tExecuting MOVI....");
                  MOVI(Read_Mem(),(short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x31:         //For ADDI Instruction
                  Console.WriteLine("\n\tExecuting ADDI....");
                  ADDI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x32:          //For SUBI Instruction
                  Console.WriteLine("\n\tExecuting SUBI....");
                  SUBI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x33:           //For MULI Instruction
                  Console.WriteLine("\n\tExecuting MULI....");
                  MULI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x34:             //For DIVI Instruction
                  Console.WriteLine("\n\tExecuting DIVI....");
                  DIVI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x35:             //For ANDI Instruction
                  Console.WriteLine("\n\tExecuting ANDI....");
                  ANDI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x36:               //For ORI Instruction
                  Console.WriteLine("\n\tExecuting ORI....");
                  ORI(Read_Mem(), (short)Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x37:              //For BZ Instruction
                  Console.WriteLine("\n\tExecuting BZ....");
                  BZ(Fetch_W());
                  break;

               case 0x38:             //For BNZ Instruction
                  Console.WriteLine("\n\tExecuting BNZ....");
                  BNZ(Fetch_W());
                  break;

               case 0x39:              //For BC Instruction
                  Console.WriteLine("\n\tExecuting BC....");
                  BC(Fetch_W());
                  break;

               case 0x3A:              //For BS Instruction
                  Console.WriteLine("\n\tExecuting BS....");
                  BS(Fetch_W());
                  break;

               case 0x3B:                //For JMP Instruction
                  Console.WriteLine("\n\tExecuting JMP....");
                  JMP(Fetch_W());
                  break;

               case 0x3C:               //For CALL Instruction
                  Console.WriteLine("\n\tExecuting CALL....");
                  CALL(Fetch_W());
                  break;

               case 0x3D:              //For ACT Instruction
                  Console.WriteLine("\n\tExecuting ACT....");
                  ACT(Fetch_W());
                  break;

                #endregion

               #region Memory Instructions

               case 0x51:             //For Movl Instruction
                  Console.WriteLine("\n\tExecuting MOVL....");
                  MOVL(Read_Mem(),Fetch_W());
                  SP[5] += 2;
                  break;

               case 0x52:               //For MovS Instruction
                  Console.WriteLine("\n\tExecuting MOVS....");
                  MOVS(Read_Mem(), Fetch_W());
                  SP[5] += 2;
                  break;

               #endregion

               #region Single Operand Operations

               case 0x71:             //For Shift Left Instruction
                  Console.WriteLine("\n\tExecuting SHL....");
                  SHL(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x72:                 //For Shoft Right Instruction
                  Console.WriteLine("\n\tExecuting SHR....");
                  SHR(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x73:                //For Rotate left Instruction
                  Console.WriteLine("\n\tExecuting RTL....");
                  RTL(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x74:                   //For Rotate right Instruction
                  Console.WriteLine("\n\tExecuting RTR....");
                  RTR(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x75:                     //For increment Instruction
                  Console.WriteLine("\n\tExecuting INC....");
                  INC(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x76:                      //For Decrement Instruction
                  Console.WriteLine("\n\tExecuting DEC....");
                  DEC(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x77:                        //For PUSH Instruction
                  Console.WriteLine("\n\tExecuting PUSH....");
                  PUSH(Fetch_B());
                  SP[5] += 1;
                  break;

               case 0x78:             //For POP Instruction
                  Console.WriteLine("\n\tExecuting POP....");
                  POP(Fetch_B());
                  SP[5] += 1;
                  break;

               #endregion

               #region No Operand Instructions

               case 0xF1:              //For RETURN Instruction
                  Console.WriteLine("\n\tExecuting RETURN....");
                  RETURN();
                  break;

               case 0xF2:              //For NOOP Instruction
                  Console.WriteLine("\n\tExecuting NOOP....");
                  NOOP();
                  break;

               case 0xF3:             //For END Instruction                                     
                  Console.WriteLine("\n\tExecuting END....");
                  Console.ReadLine();
                 // END();                
                  break;
               
               #endregion

               default:
                  Console.WriteLine("\n\tInvalid OpCode !!!");
                  Console.ReadKey();
                  Environment.Exit(0);
                  break;
           }
       }
        #endregion
    }
    
}
