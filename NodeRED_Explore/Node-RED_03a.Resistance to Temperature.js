var fx = 0;
var x = 0;
chx = msg.payload[0];
x = msg.payload[1];
if(chx==0 && x!=0)
{
    fx = x*(-0.007669) + 60.85;
}
else
{
    return
}
msg.payload = [msg.payload[0],fx]
return msg;