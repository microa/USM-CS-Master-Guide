var AIN = 0;
var Res = 0
AIN = msg.payload;
Res = 10000*((AIN[1]/5)/(1-(AIN[1]/5)))
msg.payload = [AIN[0],Res];
return msg;