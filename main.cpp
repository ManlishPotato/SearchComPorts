#include "SearchComPorts.h"

using namespace std;

int main()
{		
	while(true)
	{
		SearchComPorts cPorts;

		wstring portName[MAX_PORT_NUM]={L""};
		wstring comPort[MAX_PORT_NUM]={L""};
		int numPorts=0;

		bool result=cPorts.listComPorts(portName,comPort,numPorts);
	
		if(result || cPorts.regSpError=="FILE_NOT_FOUND")
		{
			if(numPorts>0)
			{
				for(int i=0;i<numPorts;i++) wcout<<i<<L" | "<<portName[i]<<" | "<<comPort[i]<<endl;
			}
			else cout<<"No com ports available"<<endl;
		}
		else
		{
			cout<<"Error: "<<cPorts.regError<<endl;
			cout<<"Specific: "<<cPorts.regSpError<<endl;
		}

		cout<<endl;
		cout<<"-------------Press enter to update-------------"<<endl;
		cin.get();
		system("CLS");
	}

	return 0;
}