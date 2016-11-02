#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <cmath>
#include <cstdlib>

// bu fonksyionlar disardan alindi. satirlardaki kelimeleri parse etmek icin
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
////////////////////////////////////////////////////////////////////////

namespace MLP { // multi-layer perceptron
	using std::vector;
	using std::string;
	using std::ifstream;
	using std::cout;
	using std::endl;
	
	class  Connection { // noronlar arasinda baglantiyi saglar
		
		// bunlar pointer olarak tutulmustur. cunku agirliklar surekli degisecegi icin degerleri set etmeye gerek kalmayacak
		float * m_valuePtr = nullptr;
		float * m_weightPtr = nullptr;
		
		public:
			// kurucu fonksiyon
			Connection(float  * valuePtr,float * weightPtr){
				m_valuePtr = valuePtr;
				m_weightPtr = weightPtr;
			}
			// yazdir
			void print(int index){
				cout << "Baglanti ->"<< index<< " deger = "<< (*m_valuePtr) << "\tagirlik = " << (*m_weightPtr) << endl;
			}
			
			// private degiskenlere erisim saglayicilar
			float * getValuePtr(){
				return m_valuePtr;
			}
			float * getWeightPtr(){
				return m_weightPtr;
			}
			void setValuePtr(float * ptr){
				m_valuePtr = ptr;
			}
			void setWeightPtr(float * ptr){
				m_weightPtr = ptr;
			}
	};
	
	typedef vector<Connection*> Connections;
	
	class Neuron { // yapay noron
	
		Connections m_connections;	
		string m_function;
		float m_output = 0.0f;
		float m_sum;
		
		public:
			// kurucu ve yikici fonksiyon
			Neuron(string function){
				m_function = function;
			}
			
			void sum() // norondaki toplam degeri hesaplanir
			{
				for(size_t i =0; i < m_connections.size();i++){
				//	m_sum+= m_connections.at(i) * 
				}
			}
			void transfer() // toplam degeri transfer fonksiyonundan gecirilir
			{

			}
			
			//verilen referans degiskenler ile baglanti olusturur ve ilk sefere mahsus agirligi rastgele atar
			void addConnection(float * valuePtr, float * weigthPtr){
				float agirlik = static_cast<float>(1.0 * rand() / (RAND_MAX)); // ilk agirlik rastgele ataniyor
				(*weigthPtr) = agirlik;
				m_connections.push_back(new Connection(valuePtr, weigthPtr)); // ilk deger 0 olarak veriliyor
			}
			
			//verilen index sayisina gore baglanti nesnesini donderir
			Connection * getConnection(int index){
				return m_connections.at(index);
			}
			
			// yazdir
			void print(int index){
				cout << "Noron -> " << index <<" fonksiyon = "<< m_function << "\tcikis = " << m_output << "\ttoplam = " << m_sum << endl;
				for(int i=0; i < m_connections.size(); i++){
					cout << "\t\t\t";
					m_connections.at(i)->print(i);
				}
			}
			// erisim saglayicilar
			float * getOutputPtr(){
				return &m_output;
			}
			float getOutput() const{
				return m_output;
			}
			float getSum() const{
				return m_sum;
			}
			
			~Neuron(){ // noronda ki temizlik islemleri
				for(size_t i=0; i < m_connections.size();i++){
					delete m_connections.at(i);
				}
			}
	};
	
	typedef vector<Neuron*> Neurons;
	
	class Layer { // icinde noronlari barindirir
		
		Neurons m_neurons;
		
		public:
			void addNeuron(string function) // noron ekler
			{
				m_neurons.push_back(new Neuron(function));
			}
			
			// yazdir
			void print(int index){
				cout << "Katman -> " << index << endl;
				for(int i=0; i < m_neurons.size(); i++){
					cout << "\t\t";
					m_neurons.at(i)->print(i);
				}
			}
			
			Neuron * getNeuron(int index){
				return m_neurons.at(index);
			}
			
			~Layer(){ // katmandaki temizlik islemleri
				for(size_t i=0; i < m_neurons.size();i++){
					delete m_neurons.at(i);
				}
			}
	
	};
	
	typedef vector<Layer*> Layers;
	typedef vector<float> Input;
	
	class Perceptron {
	
		Layers m_layers;
		
		// dosyadan okunan giris cikis verileri ile ilgili degiskenler
		
		vector<string> m_data; // okunan giris ve cikis degeri
		vector<float> m_inputs; // giris degerleri
		vector<float> m_outputs; // cikis degerleri
		
		// hesaplama isleri ile ilgili degiskenler
		
		float m_error; // cikisin olmasi gereken sonuca gore hatasi
		float m_averageError;
		
		float m_eta; // ogrenme hizi
		float m_alpha; // momentum degeri
		
		// datainfo dosyasindan okunacak veriler icin degiskenler
		
		string m_outfile;
		string m_inputfile;	
		
		vector<string> m_fonksiyonlar;
		
		int m_giris_sayisi;	// = 2	
		int m_cikis_sayisi; // = 1
		int m_gizli_katman_sayisi; // = 2

		vector<int> m_gizli_katman_noronlari;	 // = [ 3 , 2 ]		
		float m_ogrenme_hizi;
		float m_testveri_orani;
		int m_iterasyon;
			
		// data dosyasindan okunacak veriler icin degiskenler
		
		int m_sutun_sayisi; // = 3
		int m_satir_sayisi;
		
		void feedFoward(){
			// noronlarin hesaplamalarini yap
			
			// baslangic agirliklarini rastgele ata
		}
		void backPropagation(){
			// egitim algoritmasini calistir
		}
		
		public:

			
			void oku(string datainfo){
			
				string okunanSatir = "";
			
				// datainfo dosyasindaki bilgileri oku
			
				ifstream dosya; 
				dosya.open(datainfo); // dosyayi ac
				// 1. alinan satir data dosyasinin konumu
				getline(dosya, okunanSatir); 
				m_inputfile = split(okunanSatir,'\t').at(1);
				cout << "okunacak data dosyasi =\t" << m_inputfile << endl;
				// 2. alinan satir data dosyasindaki giris sayisi
				getline(dosya, okunanSatir); 
				m_giris_sayisi = stoi(split(okunanSatir,'\t')[1]);
				cout <<  "giris sayisi =\t" << m_giris_sayisi << endl;
				
				// 3. alinan satir gizli katmandaki noron sayilari
				getline(dosya, okunanSatir);
				vector<string> kelimeler = split(okunanSatir,'\t');
				cout << "gizli katmandaki noron sayilari =";
				for(int i = 1; i < kelimeler.size(); i++){ // ilk kelime atlandiktan sonra diger kelimeler noron sayilarini belirtir
					m_gizli_katman_noronlari.push_back(stoi(kelimeler.at(i)));
					cout << "\t" <<  m_gizli_katman_noronlari.at(i-1);
				}
				cout << endl;
				m_gizli_katman_sayisi = kelimeler.size() - 1;
				// 4. alinan satir katmanlarin transfer fonksiyonlari
				getline(dosya, okunanSatir);
				vector<string> kelimeler2 = split(okunanSatir,'\t');
				cout << "katmanlardaki transfer fonksiyonlari =";
				for(int i = 1; i < kelimeler2.size(); i++){ // ilk kelime atlandiktan sonra diger kelimeler noron sayilarini belirtir
					m_fonksiyonlar.push_back(kelimeler2.at(i));
					cout << "\t" <<  m_fonksiyonlar.at(i-1);
				}
				cout << endl;
				// 5. alinan satir ogrenme hizi
				getline(dosya, okunanSatir); 
				m_ogrenme_hizi = stof(split(okunanSatir,'\t')[1]);
				cout << "ogrenme hizi =\t" << m_ogrenme_hizi << endl;
				// 6. alinan satir test veri orani
				getline(dosya, okunanSatir); 
				m_testveri_orani = stof(split(okunanSatir,'\t')[1]);
				cout << "test veri orani =\t" << m_testveri_orani << endl;
				// 7. alinan satir iterasyon sayisi
				getline(dosya, okunanSatir); 
				m_iterasyon = stoi(split(okunanSatir,'\t')[1]);
				cout << "iterasyon sayisi =\t" << m_iterasyon << endl;
				// 8. alinan satir cikis dosyasinin konumu
				getline(dosya, okunanSatir); 
				m_outfile = split(okunanSatir,'\t')[1];
				cout << "output file =\t" << m_outfile << endl;
				
				// dosyayi kapat				
				dosya.close();
				
				// data dosyasini oku
				ifstream data;
				// dosyayi ac
				data.open(m_inputfile);
				
				// okuma islemleri
				cout << endl << "data dosyasindan okunan datalar"<< endl;
				while (getline(data, okunanSatir))
				{
					m_data.push_back(okunanSatir);
					cout << m_data.back() << endl;
				}
				
				m_satir_sayisi = m_data.size(); // data dosyasindaki toplam satir sayisinin alinmasi
				cout << "data dosyasindaki satir sayisi=\t"<< m_satir_sayisi << endl;
				
				m_sutun_sayisi = split(m_data.at(0),'\t').size(); // data dosyasindaki toplam sutun sayisinin alinmasi
				cout << "data dosyasindaki sutun sayisi=\t"<< m_sutun_sayisi << endl;
				
				m_cikis_sayisi = m_sutun_sayisi - m_giris_sayisi;
				cout << "buna gore networkte bulunacak cikis sayisi=\t"<< m_cikis_sayisi << endl;
				
			
				// dosyayi kapat				
				data.close();			
			}
				// dosyadan okunan bilgiler ile networku kuran fonksiyon
			void kur(){
		
				// katmanlari olustur
			
				for(int i=0; i < m_gizli_katman_sayisi; i++){ // gizli katman sayisi kadar gizli katman eklenir
					Layer * newLayer = new Layer();
					m_layers.push_back(newLayer);
				}
			
				Layer * cikisKatmani = new Layer(); // cikis katmani
				m_layers.push_back(cikisKatmani);
				// gizli katmandaki noronlari ekle
			
				for(int i=0; i < m_gizli_katman_sayisi; i++){
			
					// katmanlardaki noron sayilari kadar o katmana noronu, v tr. fonksiyonu ile ekle
					for(int j=0; j < m_gizli_katman_noronlari.at(i); j++){
						m_layers.at(i)->addNeuron(m_fonksiyonlar.at(i));
								
						// norona ait kac tane baglanti varsa onlar eklenir
						if(i == 0){ // eger 1.gizli katmana ekleme yapiliyorsa, baglantilar girislere gore eklenir
							for(int k=0; k < m_giris_sayisi; k++ ){
								m_layers.at(i)->getNeuron(j)->addConnection(new float(0.0f),new float(0.0f));
							}

						} else { // diger katmanlarin baglantilari onceki katmandaki noronlarin cikislarina gore eklenir

							for(int k=0; k < m_gizli_katman_noronlari.at(i-1); k++ ){
								m_layers.at(i)->getNeuron(j)->addConnection( m_layers.at(i-1)->getNeuron(k)->getOutputPtr(),new float(0.0f) );
							}
						
						}
					}
				}
				
				// cikis katmanindaki noronlari ekle
				for(int i=0; i < m_cikis_sayisi; i++ ){// cikis katmanindaki noron sayisi, data dosyasindaki cikis sayisiyla aynidir
					m_layers.back()->addNeuron(m_fonksiyonlar.back());
					
					for(int j=0; j < m_gizli_katman_noronlari.back(); j++){ // en sonda ki gizli katmanda yer alan noron sayisi
						m_layers.back()->getNeuron(i)->addConnection( m_layers.at(m_layers.size()-2)->getNeuron(j)->getOutputPtr(),new float(0.0f) );
					}
				}
			}
			void print(){
				cout << "Network -> " << endl;
				for(int i=0; i < m_layers.size(); i++){
					cout << "\t";
					m_layers.at(i)->print(i);
				}
			}
			
	};

};



int main(){
	using namespace MLP;
	using std::cout;
	
	Perceptron  net;

	net.oku("data/datainfo");
	net.kur();
	net.print();
	
	return 0;
}
