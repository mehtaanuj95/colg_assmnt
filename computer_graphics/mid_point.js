/*
Author : Anuj Bhai Mehta
Description : Bresenhem Circle Drawing Algorithm
*/

var X1 = 200, Y1 = 100, X2 = 400, Y2 = 300;


function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}
function setup()
{
    createCanvas(600, 600);
	
}

async function draw()
{
    var oldx = X1;
    var oldy = Y1;

    var dx = X2 - X1;
    var dy = Y2 - Y1;
 
    var d = dy - (dx/2);
    var x = X1, y = Y1;
 	console.log(x+" "+y);
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
 		console.log(x+" "+y);
        line(oldx, oldy, x, y);
        oldx = x;
        oldy = y;
        //await sleep(25);
    }
    noLoop();

}
 
