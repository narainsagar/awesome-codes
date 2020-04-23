using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Os_Project
{
    class Registers
    {
        public static short[] GP = new short[16];          //Initialzation of General Purpose Register
        public static ushort[] SP = new ushort[16];          //Initialzation of Special Purpose Register
        string[] Ops = {"Arithmetic","Logical", "Rotate","Shift" };
        public ushort[] Flags = { 0x0001, 0x0002, 0x0004, 0x0008 };          //Initialzation of Flags
        short temp;

        public Registers()   //Constructor of REGISTER CLASS
        {
            SP[0] = 0;
        }

        #region Show Registers and Flags

        public void Show_Reg()   //Show General and Special purpose Registers
        {
            Console.WriteLine("\nGeneral Purpose Registers \tSpecial Purpose Registers\n");
            for (int i = 0; i < 16; i++)
            {
                Console.Write("\n\tGP{0}\t\t{1}",i+1,Convert.ToString(GP[i], 16));
                Console.Write("\tSP{0}\t\t{1}", i + 1, Convert.ToString(SP[i], 16));
            }

            Console.WriteLine("\n\tFlags: {0}", Convert.ToString(SP[9],2).PadLeft(4,'0'));
        }

        #endregion

        #region Setting Flags

        

        public void Chk_And_Set_Flags(short old_val, short new_val, string operation) //Function to check and set flags
        {
            if (operation.Equals(Ops[3]) || operation.Equals(Ops[2]))
            {
                if (((old_val & 0x8000) != 0) && ((new_val & 0x8000) == 0))  // CARRY FLAG
                    SP[9] |= Flags[0];
                else
                    SP[9] &= (ushort)(~Flags[0]);
            }

            else if (operation.Equals(Ops[0]) || operation.Equals(Ops[1]))
            {
                if (((old_val & 0x8000) != 0) && ((new_val & 0x8000) == 0) || ((old_val & 0x8000) == 0) && ((new_val & 0x8000) != 0))  // OVERFLOW FLAG
                    SP[9] |= Flags[3];
                else
                    SP[9] &= (ushort)(~(ushort)Flags[3]);
            }

            SP[9] = (ushort)((new_val == 0x0000) ? SP[9] | Flags[1] : SP[9] & (~(ushort)Flags[1]));   // ZERO FLAG
            SP[9] = (ushort)(((new_val & 0x8000) != 0) ? SP[9] | Flags[2] : SP[9] & (~(ushort)Flags[2]));       // SIGN FLAG

        }

        #endregion

        #region Register-Register Implementation

        public void MOV(byte i1, byte i2)   //Perform MOV Instruction 
        {
            GP[i1] = GP[i2];
        }

        public void ADD(byte i1, byte i2)    //Perform ADD Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] + GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void SUB(byte i1, byte i2)      //Perform SUB Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] - GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void MUL(byte i1, byte i2)      //Perform MUL Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] * GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void DIV(byte i1, byte i2)    //Perform DIV Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] / GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void AND(byte i1, byte i2)      //Perform AND Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] & GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[1]);
        }


        public void OR(byte i1, byte i2)      //Perform OR Instruction 
        {
            temp = GP[i1];
            GP[i1] = (short)(GP[i1] | GP[i2]);

            Chk_And_Set_Flags(temp, GP[i1], Ops[1]);
        }

        #endregion

        #region Register-Immediate Implementation


        public void MOVI(byte i1, short i2)   //Perform MOVI Instruction 
        {
            SP[15] = (ushort)i2;
            GP[i1] = (short)SP[15];
        }


        public void ADDI(byte i1, short i2)   //Perform ADDI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] + SP[15]);
    
            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }

        public void SUBI(byte i1, short i2)      //Perform SUBI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] - SP[15]);
    
            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void MULI(byte i1, short i2)    //Perform MULI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] * SP[15]);
   
            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }

        public void DIVI(byte i1, short i2)  //Perform DIVI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] / SP[15]);
   
            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void ANDI(byte i1, short i2)   //Perform ANDI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] & SP[15]);
  
            Chk_And_Set_Flags(temp, GP[i1], Ops[1]);
        }

        public void ORI(byte i1, short i2)   //Perform ORI Instruction 
        {
            temp = GP[i1];
            SP[15] = (ushort)i2;
            GP[i1] = (short)(GP[i1] ^ SP[15]);
    
            Chk_And_Set_Flags(temp, GP[i1], Ops[1]);
        }

        public void BZ(ushort val)   //Perform BZ Instruction 
        {
            if ((SP[9] & Flags[1]) != 0)
            {
                if ((SP[3] + val) < SP[4])
                {
                    SP[5] = (ushort)(SP[3] + val);
                }

                else
                {
                    Console.WriteLine("\tInvalid Adrress !!!\n\tCannot Branch !!!");
                    SP[5] += 2;
                    Console.ReadKey();
                    Environment.Exit(0);
                }
            }

            else
            {
                Console.WriteLine("\tZero Flag Not Set !!!");
                SP[5] += 2;
                Console.ReadKey();
                Environment.Exit(0);
            } 
        }

        public void BNZ(ushort val)    //Perform BNZ Instruction 
        {
            if ((SP[9] & Flags[1]) == 0)
            {
                if ((SP[3] + val) < SP[4])
                {
                    SP[5] = (ushort)(SP[3] + val);
                }

                else
                {
                    Console.WriteLine("\tInvalid Adrress !!!\n\tCannot Branch !!!");
                    SP[5] += 2;
                    Console.ReadKey();
                    Environment.Exit(0);
                }
            }

            else
            {
                Console.WriteLine("\tZero Flag Not Set !!!");
                SP[5] += 2;
                Console.ReadKey();
                Environment.Exit(0);
            } 
        }

        public void BC(ushort val)    //Perform BC Instruction 
        {
            if ((SP[9] & Flags[0]) != 0)
            {
                if ((SP[3] + val) < SP[4])
                {
                    SP[5] = (ushort)(SP[3] + val);
                }

                else
                {
                    Console.WriteLine("\tInvalid Adrress !!!\n\tCannot Branch !!!");
                    SP[5] += 2;
                    Console.ReadKey();
                    Environment.Exit(0);
                }
            }

            else
            {
                Console.WriteLine("\tZero Flag Not Set !!!");
                SP[5] += 2;
                Console.ReadKey();
                Environment.Exit(0);
            } 
        }

        public void BS(ushort val)   //Perform BS Instruction 
        {
            if ((SP[9] & Flags[2]) != 0)
            {
                if ((SP[3] + val) < SP[4])
                {
                    SP[5] = (ushort)(SP[3] + val);
                }

                else
                {
                    Console.WriteLine("\tInvalid Adrress !!!\n\tCannot Branch !!!");
                    SP[5] += 2;
                    Console.ReadKey();
                    Environment.Exit(0);
                }
            }

            else
            {
                Console.WriteLine("\tZero Flag Not Set !!!");
                SP[5] += 2;
                Console.ReadKey();
                Environment.Exit(0);
            } 
        }



        public void JMP(ushort val)    //Perform JMP  Instruction 
        {   
            if ((SP[3] + val) < SP[4])
            {
                SP[5] = (ushort)(SP[3] + val); 
            }

            else
            {
                Console.WriteLine("\tInvalid Adrress !!!\n\tCannot Jump !!!");
                SP[5] += 2;
                Console.ReadKey();
                Environment.Exit(0);
            }
        }


        public void ACT(ushort val)   //Perform ACT Instruction 
        {
            SP[5] = val;
        }

        #endregion

        #region Single-Operand Implementation

        public void SHL(byte i1)   //Perform SHIFT LEFT Instruction 
        {
            short temp = GP[i1];

            GP[i1] = (short)(GP[i1] << 1);

            Chk_And_Set_Flags(temp, GP[i1], Ops[3]);
        }

        public void SHR(byte i1)    //Perform SHIFT RIGHT Instruction 
        {
            short temp = GP[i1];

            GP[i1] = (short)(GP[i1] >> 1);

            Chk_And_Set_Flags(temp, GP[i1], Ops[3]);
        }

        public void RTL(byte i1)    //Perform ROTATE LEFT Instruction 
        {
            temp = GP[i1];
            short MSB = (short)(((temp & 0x8000) !=0)? 1 : 0);
            GP[i1]  = (short)(GP[i1] << 1);
            GP[i1] |= MSB;

            Chk_And_Set_Flags(temp, GP[i1], Ops[2]);
        }


        public void RTR(byte i1)    //Perform ROTATE RIGHT Instruction 
        {
            temp = GP[i1];
            short LSB = (short)(((temp & 0x0001) != 0) ? 1 : 0);
            GP[i1] = (short)(GP[i1] >> 1);
            GP[i1] |= LSB;

            Chk_And_Set_Flags(temp, GP[i1], Ops[2]);
        }


        public void INC(byte i1)   //Perform INC Instruction 
        {
            temp = GP[i1];
            GP[i1]++;

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }


        public void DEC(byte i1)    //Perform DEC Instruction 
        {
            temp = GP[i1];
            GP[i1]--;

            Chk_And_Set_Flags(temp, GP[i1], Ops[0]);
        }

        #endregion

        #region No Operand Implementation

        public void NOOP()    //Perform NOOP Instruction 
        {
            Console.WriteLine("\n\tNo Operation !!!");
        }

        public void END()    //Perform END Instruction 
        {
          //  Console.WriteLine("\n\tEND Instruction !!!");
          //  Console.ReadKey();
            Environment.Exit(0);
        }

        #endregion
    }
}