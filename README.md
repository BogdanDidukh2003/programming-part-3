# programming-part-3

### Running in IDE
Programs have CMakeLists.txt file for convenient importing to CLion

### Running in console (Linux CLI)
Execute appropriate following command:

#### Lab 1
<code>cd Lab1; cp data.txt ../; g++ models/Helicopter.h models/Helicopter.cpp models/HelicoptersManager.h models/HelicoptersManager.cpp main.cpp -o main; ./main; rm main; cd ..; rm data.txt</code>

#### Lab 2
<code>cd Lab2; cp discnt.in ../; g++ main.cpp -o main; ./main; rm main; cd ..; rm discnt.in; cp discnt.out Lab2/; rm discnt.out</code>

#### Lab 3_bfs
<code>cd Lab3_bfs; cp data1.in ../; cp data2.in ../; cp data3.in ../; g++ main.cpp -o main; ./main; rm main; cd ..; rm data1.in; rm data2.in; rm data3.in; cp data.out Lab3_bfs/; rm data.out</code>

#### Lab 4
<code>cd Lab4; cp data.in ../; g++ main.cpp -o main; ./main; rm main; cd ..; rm data.in; cp data.out Lab4/; rm data.out</code>

#### Lab 5
<code>cd Lab5; cp data1.in ../; cp data2.in ../; cp data3.in ../; cp data4.in ../; g++ main.cpp -o main; ./main; rm main; cd ..; rm data1.in; rm data2.in; rm data3.in; rm data4.in; cp data.out Lab5/; rm data.out</code>
