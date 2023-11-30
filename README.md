# V1.1

Programa perrasyta nuo pagrindu vietoj struct naudojant tik class Studentas. Klasei realizuoti getteriai, setteriai, konstruktorius ir destruktorius. Programos testavimui naudoti tik 1000000 ir 10000000 eiluciu duomenu failai. Programos veikimo laikai, palyginimas su ankstesne struct naudojusia programa ir optimizavimo flagai pateikti zemiau.

Sios programos testavimui naudotas kitas kompiuteris, todel laikai skiriasi nuo ansktesniu. Testavimui naudoti duomenu failai liko tie patys.

Specs: i5-1035G1 CPU @ 1.00GHz   1.19 GHz, 8.00 GB RAM

|Tipas|1000000|10000000|
|---|---|---|
|Struct|89.665 s|1210.51 s|
|Class|139.537 s|1771.64 s|

|Flagas|1000000|10000000|Failo dydis|
|---|---|---|---|
|O1|165.076 s|1781.04 s|186 KB|
|O2|120.81 s|1503.36 s|195 KB|
|O3(OX)|122.508 s|1484.87 s|195 KB|

Class testavimao greitis

![image](https://github.com/MartynasTap/2.0/assets/145481815/840968c0-b35a-4854-a60a-5f92a9999feb)

O1 flago testavimo greitis

![image](https://github.com/MartynasTap/2.0/assets/145481815/d7f5b8f6-4854-4cf1-930c-3d8e23fada84)

02 flago testavimo greitis

![image](https://github.com/MartynasTap/2.0/assets/145481815/4a65fe3c-7300-49ee-babd-d1de6bb8ed2c)

O3 (Ox) flago testavimo greitis

![image](https://github.com/MartynasTap/2.0/assets/145481815/a9c6e942-b3f0-4fac-b159-f2cff6350542)

