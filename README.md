# hansi
Kode for å ta imot data fra HAN- port på AMS måler
Sender det så videre til Node-red.

# Oppsett
1. Kopier filen `config_template.h` til `config_prod.h`
2. Rediger infoen i `config_prod.h`

I node-red kan du sende dataen hvor du vil.

![Node-red flow](/flow1.PNG)

Ut kommer dekodet data.
Her kan du videresende det på din måte : 
MQTT, JSON-kall, røyksignaler osv..

Jeg sender data videre til Homeseer 3 PRO
i JSON-format

Under ser du hva som kommer fra debug-noden:

![Node-red resultat](/debug.PNG)
