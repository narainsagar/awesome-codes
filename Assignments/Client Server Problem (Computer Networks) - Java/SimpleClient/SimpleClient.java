/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package simpleclient;

/**
 *
 * @author Narain Sagar (NineS)
 */
import java.net.*;
import java.io.*;
import java.util.Scanner;

public class SimpleClient
{
   public static void main(String[] args)
   {
      try
      {
         Scanner input = new Scanner(System.in);
         int port;
         String IP;
        
         System.out.println("IP: ");
         IP = input.nextLine();  
        
         System.out.println("Port Number: ");
         port = input.nextInt();  
    
         Socket client = new Socket(IP, port);
         
         // remote address and port
         System.out.println("\t\tConnected..!!");
         System.out.println("Remote server: "+client.getInetAddress());
         System.out.println("Remote port: " + client.getPort());
         System.out.println("Port Local client: "+client.getLocalPort());
         
         // Server Message respond..
         InputStream in = client.getInputStream(); 
         //  byte => char
         InputStreamReader in_reader = new InputStreamReader(in);
         // buffered Reader
         BufferedReader server_respond = new BufferedReader(in_reader);
         
         // Client Message Send..to server
         OutputStream out = client.getOutputStream();
         // Print Writer
         PrintWriter client_writer = new PrintWriter(out);
         
         // Data
         BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
         
         System.out.println("\t\t**** Start Chatting with Server. ****");
         
         String client_message = "";
         do {      
                System.out.print("send message: ");
                client_message = userInput.readLine(); 
                client_writer.println(client_message);
                client_writer.flush();
                String get_reply = server_respond.readLine();
                System.out.println("Server Replied: " + get_reply);
         } while (!client_message.equalsIgnoreCase("close"));
         Thread.sleep(1000);
       }
       catch (InterruptedException e) {
             e.printStackTrace();
       }
       catch (IOException e) {
             System.out.println(e);
       }
   }
} 