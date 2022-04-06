### MosquittoExplore for CCS527
####quick note
<p>Step 1.Install Mosquitto:https://mosquitto.org/download/</p>
<p>Step 2.open MS DOS, CD C:\Program Files\mosquitto (mosquitto install directory)</p>
<p>Step 3.open mosquitto as Broker</p>
<p>Step 4.open another MS DOS, into same directory and: mosquitto_sub -t mymos (subscribe the topic:mymos)</p>
<p>Step 5.open third MS DOS, same operation and: mosquitto_pub -t mymos -m 3.1415 (publish message 3.1415 to the topic:mymos)</p>
<p>after Step 5, the second window will received a msg that is 3.1415 from the third window.</p>

#### tips
<p>Check Broker(server) is on working: Use admin open MS DOS and type: netstat -ban, then you can find the mosquitto and its port</p>
