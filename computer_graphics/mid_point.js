/*
Author : Anuj BHai Mehta
Description : Mid Point Line Drawing Algorithm
*/

var X1 = 200, Y1 = 100, X2 = 400, Y2 = 300;

function setup()
{
    createCanvas(600, 600);
	
}

function draw()
{
    var oldx = X1;
    var oldy = Y1;

    var dx = X2 - X1;
    var dy = Y2 - Y1;
 
    var d = dy - (dx/2);
    var x = X1, y = Y1;
 
    line(oldx, oldy, x, y);
    oldx = x;
    oldy = y;
    while (x < X2)
    {
        x++;
 
        if (d < 0)
            d = d + dy;
 
        else
        {
            d += (dy - dx);
            y++;
        }
 
        line(oldx, oldy, x, y);
        oldx = x;
        oldy = y;
    }
    noLoop();

}
 
