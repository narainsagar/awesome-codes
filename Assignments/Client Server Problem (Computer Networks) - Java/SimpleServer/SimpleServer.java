/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package simpleserver;

/**
 *
 * @author gax92
 */

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class SimpleServer
{
       public static void main(String[] args)
       {
          try
          {
              Scanner input_port = new Scanner(System.in);
              int port;
              System.out.println("Port Number: ");
              port = input_port.nextInt();
              ServerSocket theServer = new ServerSocket(port);
              System.out.println("\n\tStarted Listening......!!!");  
              while(true)    // loop infinite
              {    
                Socket connection = theServer.accept();
                System.out.println("\n\tConnected: Got a Client..!!!");  
                
                // Receive Message from Client..
                InputStream in = connection.getInputStream();
                // byte => char
                InputStreamReader in_reader =new InputStreamReader(in);
                BufferedReader client_buffer = new BufferedReader(in_reader);
                
                // Send reply to Client..
                OutputStream out = connection.getOutputStream();
                PrintWriter server_writer = new PrintWriter(out);
                BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
                String client_message;
                
                while((client_message = client_buffer.readLine()) != null)
                {
                    System.out.println("Client message: " + client_message);
                    System.out.print("Send Reply: ");      
                    String server_message = input.readLine();
                    // server-reply...
                    server_writer.println(server_message);
                    server_writer.flush();
                }               
             }     
          } 
          catch (SocketException se) {
               System.err.println(se);
          }
        catch (IOException e) {
             System.out.println(e);
          }
       }
} 