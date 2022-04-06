var Lux = 0;
var Temp = 0;
chx = msg.payload[0];
Lux = msg.payload[1];
Temp = msg.payload[1];
Moist = msg.payload[1];
if(chx==0 && Temp>0 && Temp<1000)//if Ch0 was link to thermistor
{
    if(Temp>30)
    {
        msg.payload='r';
    }
    else
    {
        msg.payload='s';
    }

}
else if(chx==1 && Lux>0 && Lux<100000)//if Ch1 was link to Photoresistor
{
    if(Lux>1500)
    {
        msg.payload='g';
    }
    else
    {
        msg.payload='h';
    }
}
else if(chx==2 && Moist>50 && Moist<100)//if Ch1 was link to Photoresistor
{
    if(Moist>50)
    {
        msg.payload='b';
    }
    else
    {
        msg.payload='c';
    }
}
else
{
    return
}
/*

*/
return msg;