#include <allegro.h>
#include <iostream>
#define Right 1 
#define Left  2 
#define Up    3
#define Down  4

using namespace std;
void PixelCollision1(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer);
void PixelCollision2(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer);
void PixelCollision(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer);

int main(){
    
       int c;

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode( GFX_AUTODETECT, 800, 600, 0, 0);
     


 BITMAP *buffer=create_bitmap(800,600);
 BITMAP *bs=load_bitmap("MAZE.bmp",NULL);
 BITMAP *bss=load_bitmap("boy.bmp",NULL);
 BITMAP *bsss=load_bitmap("boy.bmp",NULL);
  
  
  
  //sprite 
  int px=32, py=48, x=30, y=20;  //x and y are starting positions
  const int G=1;
  int velx,vely;
  velx=vely=3;
  bool gof=true;
  int dir = Right;
  int moveSpeed=5;
 //sprite 2       

      int px1=32, py1=48, x1=30, y1=50;  //x and y are starting positions
      bool gof1=true;
      int velx1,vely1;
      velx1=vely1=3;
      int dir1 = Right;
      int moveSpeed1=5;
         
    while(!key[KEY_ESC])
    {    
        if(key[KEY_DOWN])
        {
            gof=true;
            
            px+=32;
            py=0;
            if(px>64) px=0;
            y+=3;
       	dir = Down; }
        else if(key[KEY_UP])
        {
            gof=false;
            vely=0;
            
            px+=32;
            py=48;
            if(px>64) px=0;
            
            y-=3;    
       	dir = Up; }
        
        else if(key[KEY_LEFT])
        {
            px+=32;
            py=96;
        
            if(px>64) px=0;
            
            x-=3;    
            dir = Left;}
        else if(key[KEY_RIGHT])
        {
            px+=32;
            py=96+48;
            if(px>64) px=0;
            
            x+=3;    
            dir = Right; }

if(key[KEY_S])
        {
            gof1=true;
            
            px1+=32;
            py1=0;
            if(px1>64) px1=0;
            y1+=3;
       	dir1 = Down; }
        else if(key[KEY_W])
        {
            gof1=false;
            vely1=0;
            
            px1+=32;
            py1=48;
            if(px1>64) px1=0;
            
            y1-=3;    
       	dir1 = Up; }
        
        else if(key[KEY_A])
        {
            px1+=32;
            py1=96;
        
            if(px1>64) px1=0;
            
            x1-=3;    
            dir1 = Left;}
        else if(key[KEY_D])
        {
            px1+=32;
            py1=96+48;
            if(px1>64) px1=0;
         if(key[KEY_SPACE])
         {x1=+6;}
         else
         {   
            x1+=3;}    
dir1 = Right;        }
if(key[KEY_SPACE])
        {
            
            if(py==96+48)
            {
            x+=6;
            }
            if(py==96)
            {
            x-=6;
            }
            if(py==0)
            {
            y+=6;
            }   
            if(py==48)
            {
            y-=6;
            }        
            }
        if(key[KEY_Z])
        {
            if(py1==96+48)
            {
            x1+=6;
            }
            if(py1==96)
            {
            x1-=6;
            }
            if(py1==0)
            {
            y1+=6;
            }   
            if(py1==48)
            {
            y1-=6;
            }
        }        
          
       masked_blit(bs,buffer,0,0,0,0,800,600);
     masked_blit(bss,buffer,px,py,x,y,32,48);
       masked_blit(bsss,buffer,px1,py1,x1,y1,32,48);
       
       //sprite 1
     PixelCollision(x, y, 32, 48, moveSpeed, dir, makecol(0, 64, 64), buffer); 
     PixelCollision1(x, y, 32, 48, moveSpeed, dir, makecol(255, 0, 0), buffer);
    
    
    //player 2  
      PixelCollision(x1, y1, 32, 48, moveSpeed1, dir1, makecol(0, 64, 64), buffer);
      PixelCollision2(x1, y1, 32, 48, moveSpeed, dir, makecol(255, 0, 0), buffer);
          
          
       //Clear
        blit(buffer,screen,0,0,0,0,800,600);
        rest(50);
        clear_bitmap(buffer);
    }

    readkey();
    return 0;
    }   
    END_OF_MAIN();
    
    
void PixelCollision(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer)
{
	for(int i = x; i < x + width; i++)
	{
		for(int j = y; j < y + height; j++)
		{
			if(getpixel(Buffer, i , j) == col)
			{
				if(dir == Right)
					x -= moveSpeed; 
				else if(dir == Left)
					x += moveSpeed; 
				else if(dir == Up)
					y += moveSpeed; 
				else 
					y -= moveSpeed;
					
					
				break; // This is important. If you remove this then you'll notice a glitch in the collision process
				// If 2 or more pixels have collided with the box and say you were moving right then it would be 
				// x -= moveSpeed * 2 because there's 2 pixels. That means the box will move 2 far back. The break statement removes that 
				// glitch and just exits the for loop
			}
		}
	}
}
    
    
    void PixelCollision1(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer)
{
	for(int i = x; i < x + width; i++)
	{
		for(int j = y; j < y + height; j++)
		{
			if(getpixel(Buffer, i , j) == col)
			{
				if(dir == Right)
					x -= moveSpeed; 
				else if(dir == Left)
					x += moveSpeed; 
				else if(dir == Up)
					y += moveSpeed; 
				else 
					y -= moveSpeed;
					
					 allegro_message(" YOU DID IT PLAYER 1 ");
				break; // This is important. If you remove this then you'll notice a glitch in the collision process
				// If 2 or more pixels have collided with the box and say you were moving right then it would be 
				// x -= moveSpeed * 2 because there's 2 pixels. That means the box will move 2 far back. The break statement removes that 
				// glitch and just exits the for loop
			}
		}
	}
}

void PixelCollision2(int &x, int &y, int width, int height, int moveSpeed, int dir, int col, BITMAP *Buffer)
{
	for(int i = x; i < x + width; i++)
	{
		for(int j = y; j < y + height; j++)
		{
			if(getpixel(Buffer, i , j) == col)
			{
				if(dir == Right)
					x -= moveSpeed; 
				else if(dir == Left)
					x += moveSpeed; 
				else if(dir == Up)
					y += moveSpeed; 
				else 
					y -= moveSpeed;
					
					 allegro_message(" YOU DID IT PLAYER 2 ");
				break; // This is important. If you remove this then you'll notice a glitch in the collision process
				// If 2 or more pixels have collided with the box and say you were moving right then it would be 
				// x -= moveSpeed * 2 because there's 2 pixels. That means the box will move 2 far back. The break statement removes that 
				// glitch and just exits the for loop
			}
		}
	}
}
    
    
                 
    


