using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
                                /* This Code Implements a Virtual Machine.
                                 * The Code to Run on VM is Given as Hex in Text File
                                 * This Code Picks The File From Desktop.
                                 */
namespace Os_Project
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Gray;        // Setting BackGround Color.
            Console.Clear();

            Console.ForegroundColor = ConsoleColor.DarkRed;     // Setting ForeGround Color.

            Console.WriteLine("\n\t\tWelcome To Virtual Machine !!!\n");        // Header.
         
            Menu:
            try
            {
                Memory M = new Memory();        // Generating Virtual Memory And Registers.
                int choice = -1;

                do
                {
                    Console.WriteLine("\n\nEnter 1 To Load A Process, ");
                    Console.WriteLine("Enter 2 To Run The Loaded Process, ");
                    Console.WriteLine("Enter 3 To Load Highest Priority Process To Running Queue, ");
                    Console.WriteLine("Enter 4 To Show Value Of Registers, ");
                    Console.WriteLine("Enter 5 To Show Queues, ");
                    Console.WriteLine("Enter 6 To Show Used Frames List, ");
                    Console.WriteLine("Enter 7 To Show FREE Frames NUMBER, ");
                    Console.WriteLine("Enter 8 To Show FREE Frames List, ");
                    Console.Write("Enter 0 To Exit  \n\n>>> ");
                    choice = int.Parse(Console.ReadLine());

                    if (choice == 1) M.Generate_PCB();
                    if (choice == 2)
                    {
                        if (M.Execute()) continue;
                        else Console.WriteLine("\t\tError In Execution !!!");
                    }
                    if (choice == 3) M.Highest_In_Running();
                    if (choice == 4) M.Show_Reg();
                    if (choice == 5) M.Show_Queues();
                    if (choice == 6) M.Show_UsedFrameList();
                    if (choice == 7) M.Show_FreeFrameNumber();
                    if (choice == 8) M.Show_FreeFrameList();
                           
                } while (choice != 0);
                
            }

            catch (Exception E)                 // Catches Any Exception Occured While Execution And Displays Error.
            {
                Console.WriteLine("\n\tERROR: " + E.Message );
                goto Menu;
            }

            Console.ReadLine();
        }
    }
}
