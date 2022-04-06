var Channel = 0;
var ANx = 0;
if (msg.payload[0]==='A')
{
    Channel = Number(msg.payload[3]);
    if(msg.payload[8]==="\n")
    {
        Number(msg.payload[8]);
    }
    if(msg.payload[9]==="\n")
    {
        Number(msg.payload[7])*10+Number(msg.payload[8]);
    }
    if(msg.payload[10]==="\n")
    {
        ANx = Number(msg.payload[6])*100+Number(msg.payload[7])*10+Number(msg.payload[8]);
    }
    if(msg.payload[11]==="\n")
    {
        ANx = Number(msg.payload[6])*1000+Number(msg.payload[7])*100+Number(msg.payload[8])*10+Number(msg.payload[9]);
    }
}
msg.payload = [Channel,ANx*0.003];
return msg;