#include <iostream>
#include <cmath>
#include <cstdlib>

float testveri_orani = 0.2f;
int veri_sayisi = 1000;

int main(){
	using std::cout;
	using std::endl;
	
	int input1;
	int input2;
	int output1;
	
	// egitim verisini olustur
	for(int i=0; i < veri_sayisi * (1-testveri_orani); i++){
		input1 = static_cast<int>(2.0 * rand() / (RAND_MAX));
		input2 = static_cast<int>(2.0 * rand() / (RAND_MAX));
		output1 = input1 ^ input2; // xor islemi
		cout << input1 << "\t" << input2 << "\t" << output1 << endl;
	}
	// test verisini olustur
	for(int i=0; i < veri_sayisi * testveri_orani; i++){
		input1 = static_cast<int>(2.0 * rand() / (RAND_MAX));
		input2 = static_cast<int>(2.0 * rand() / (RAND_MAX));
		output1 = input1 ^ input2; // xor islemi
		cout << input1 << "\t" << input2 << "\t" << output1 << endl;
	}

}
