/*
Author : Anuj BHai Mehta
Description : Bresenhem Line Drawing Algorithm
*/

var x1 = 100, y1 = 200, x2 = 300, y2 = 400;

function setup() 
{
	createCanvas(600, 600);
	//ellipse(x1,y1,5,5);
	//ellipse(x2,y2,5,5);
}

function draw()
{	
	var oldx = x1;
	var oldy = y1; 
	var m_new = 2 * (y2 - y1);
   	var slope_error_new = m_new - (x2 - x1);
   	for (var x = x1, y = y1; x <= x2; x++)
   	{
      	//cout << "(" << x << "," << y << ")\n";
 		console.log(x + " " + y);
      	slope_error_new += m_new;
 		line(oldx, oldy, x, y);
      	if (slope_error_new >= 0)
      	{
         	y++;
         	slope_error_new  -= 2 * (x2 - x1);
      	}
      	oldx = x; oldy = y;

   	}
   	noLoop();
}

function bresenham(x1, y1, x2, y2)
{
	
}
