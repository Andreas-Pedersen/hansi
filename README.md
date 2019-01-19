# hansi
Kode for å ta imot data fra HAN- port på AMS måler
Sender det så videre til Node-red.

I node-red kan du sende dataen hvor du vil.

![Node-red flow](/flow1.PNG)

Ut kommer dekodet data slik som fra debug-noden.
Her kan du videresende det på din måte : 
MQTT, JSON-kall, røyksignaler osv..

Jeg sender data videre til Homeseer 3 PRO
i JSON-format

![Node-red resultat](/debug.PNG)
