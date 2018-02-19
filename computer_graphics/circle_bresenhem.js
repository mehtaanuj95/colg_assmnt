/*
Author : Anuj Bhai Mehta
Description : Bresenhem Circle Drawing Algorithm
*/

var xc = 150, yc = 150, r = 100;


function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}
function setup()
{
    createCanvas(600, 600);
	
}

async function draw()
{
    var x = 0, y = r;
    var d = 3 - 2 * r;
    while (y >= x)
    {
        ellipse(xc+x, yc+y, 1,1);  ellipse(xc-x, yc+y, 1,1);
        ellipse(xc+x, yc-y, 1,1);  ellipse(xc-x, yc-y, 1,1);
        ellipse(xc+y, yc+x, 1,1); ellipse(xc-y, yc+x, 1,1);
        ellipse(xc+y, yc-x, 1,1); ellipse(xc-y, yc-x, 1,1);
        
        x++;
        if (d > 0)
        {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }
    noLoop();

}
 
