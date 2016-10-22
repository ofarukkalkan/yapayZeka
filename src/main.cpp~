#include <vector>
#include <functional>

namespace MLP { // multi-layer perceptron

	using std::vector;
	using std::function;

	class  Connection { // noronlar arasinda baglantiyi saglar
	
		float m_value = 0.0f;
		float m_weight = 0.0f;
		
		public:
		
			// kurucu ve yikici fonksiyon
			Connection(float value,float weight);
			
			// erisim saglayicilar
			void setValue(float value);
			void setWeight(float value);
			float getValue() const;
			float getWeight() const;
	};
	
	typedef vector<Connection*> Connections;
	typedef function<float(float)> TransferFunction;
	
	class Neuron { // yapay noron
	
		Connections m_inputs;	
		TransferFunction m_function = nullptr;
		float m_output = 0.0f;
		
		public:
			// kurucu ve yikici fonksiyon
			Neuron(TransferFunction function);
			
			void run(); // noronu calistirir
			
			// erisim saglayicilar
			float getOutput() const;
	};
	
	typedef vector<Neuron*> Neurons;
	
	class Layer { // icinde noronlari barindirir
		
		Neurons m_neurons;
		
		public:
			void addNeuron(TransferFunction function); // noron ekler
			void run(); // katmandaki noronlari calistirir
	
	};
	
	typedef vector<Layer*> Layers;
	typedef vector<float> Input;
	
	class Perceptron {
	
		Layers m_layers;
		float m_output;
		
		void feedFoward();
		void backPropagation();
		
		public:
			void addLayer(Layer layer);
			void run(Input input,int iteration); // perceptronu verilen girislerle calistirir
			void displayResults() const;
			
	};

}

float sigmoid(float value){
	return 1;
}

int main(){
	using namespace MLP;
	using std::vector;
	
	TransferFunction f_sigmoid = sigmoid;

	Layer giris;
	giris.addNeuron(f_sigmoid);
	giris.addNeuron(f_sigmoid);
	giris.addNeuron(f_sigmoid);
	
	Layer gizli;
	giris.addNeuron(f_sigmoid);
	giris.addNeuron(f_sigmoid);
	
	Layer cikis;
	giris.addNeuron(f_sigmoid);

	Input girisler;
	
	girisler.push_back(1.0f);
	girisler.push_back(0.0f);
		
	Perceptron net;
	net.addLayer(giris);
	net.addLayer(gizli);
	net.addLayer(cikis);
	
	
	net.run(girisler,200); // 200 defa verilen girisler ile calistirir
	
	net.displayResults(); // sonuclari gosterir
	
	
	return 0;
}
