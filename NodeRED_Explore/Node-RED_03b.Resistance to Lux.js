var fx = 0;
var x = 0;
chx = msg.payload[0];
x = msg.payload[1];
if(chx==1 && x!=0)
{
    fx = 40210*Math.exp(-0.005908*x) + 2799*Math.exp(-0.0009271*x);
}
else
{
    return
}
msg.payload = [msg.payload[0],fx]
return msg;