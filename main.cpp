#include <iostream>
#include <string>
#include "ABB.h"
using namespace std;

#include <iostream>

class Pessoa
{
public:
	string nome;
	int id;
   

	Pessoa();
	
    Pessoa::Pessoa(string n, int i);
    
    Arvore<int, Pessoa> *amizades;
  	void Pessoa::CadastrarAmizade(Arvore<int, Pessoa> * & principal, int id1, int id2);
    void Pessoa::RemoverAmizade(int id1, int id2);
    bool Pessoa::ConsultarAmizade(int id1, int id2, Arvore<int, Pessoa> * & principal);
};


Pessoa::Pessoa()
{

    nome = "Vazio";
	id = -1;
	amizades = NULL;
}


Pessoa::Pessoa(string n, int i)
{
	nome = n;
	id = i;
    amizades = new Arvore<int, Pessoa>();
}


void Pessoa::CadastrarAmizade(Arvore<int, Pessoa> * & principal, int id1, int id2)
{ 

    Pessoa p2 = principal->Buscar(id2);
    amizades->Inserir(id2, p2);
    p2.amizades->Inserir(id1, *this);
      
}


bool Pessoa::ConsultarAmizade(int id1, int id2, Arvore<int, Pessoa> * & principal)
{
    
    Pessoa pessoa2 = principal->Buscar(id2);
    
    if(amizades->Buscar(id2).id != -1 && pessoa2.amizades->Buscar(id1).id != -1 ){
        return true;    
    }
    else {
        return false;
    }
}





int main()
{
	
    
	Arvore<int, Pessoa> *arvore = new Arvore<int, Pessoa>();
  

    cout << "ESCREVA ALGUMA OPCAOO: " << endl;
    cout << endl;
    cout << "- INSERIR" << endl;
    cout << "- BUSCAR" << endl;
    cout << "- REMOVER" << endl;
    cout << "- IMPRIMIR" << endl;
    cout << "- P/ CADASTRAR AMIZADE escreva CADASTRAR/cadastrar" << endl;
    cout << "- P/ CONSULTAR AMIZADE escreva CONSULTAR/consultar" << endl;
    cout << "- P/ REMOVER AMIZADE escreva REAMIZADE/reamizade" << endl;
    cout << "- SAIR" << endl;
    cout << endl;
    cout << "___________________________________________________________" << endl;
    
    string opcao;
	cin >> opcao;
	while(opcao != "SAIR")
	{
		if(opcao == "INSERIR" || opcao == "inserir")
		{
			string nome, lixo1;
			int id1;
			cout << endl;
			cout << "Digite a id da pessoa p/ ser inserido na arvore: " << endl;
			cin >> id1;
			
			cout << "Digite o nome da pessoa p/ ser inserido na arvore: " << endl;
			getline(cin, lixo1);
            getline(cin, nome);
		
		
		    Pessoa p(nome, id1);
		    
		    arvore->Inserir(id1, p);
		    cout << endl;
		    arvore->Imprime();
            
		  			
		}
		else if(opcao ==  "BUSCAR" || opcao == "buscar")
		{
			int id;
			cout << endl;
			cout << "Escreva o id da pessoa p/ buscar: "<< endl;
			cin >> id;
			cout << endl;
		
		    Pessoa p = arvore->Buscar(id);
		    if(arvore->Buscar(id).id != -1)    
            {       
                cout<< p.id << " " << p.nome << endl;
                cout << endl;
                cout << "Amizades " << endl;
                p.amizades->Imprime();
            }
            else
                cout << "Id nao foi encontrado no sistema!"<<endl;
   
		}
		else if(opcao == "REMOVER" || opcao == "remover")
		{
			int id;
			cout << endl;
			cout << "Escreva o id p/ remover: " << endl;
            cin >> id;
			
            Pessoa p = arvore->Buscar(id);
            if(arvore->Buscar(id).id != -1)
            {
			    cout << "A pessoa de "<< id <<" chamada " << p.nome <<" foi removida!"<<endl;
			    arvore->Remover(id);
			    cout << endl << "Arvore atual"<<endl;
			    arvore->Imprime();  
            }
            else
                cout << "Id nao foi encontrado no sistema!" <<endl;
		      
		}
		else if(opcao == "IMPRIMIR" || opcao == "imprimir")
		{
            cout << endl;
            arvore->Imprime();
		}
		
        else if(opcao == "CADASTRAR" || opcao == "cadastrar")
        {
            int id1, id2;
            cout << endl;
            cout << "Escreva o id p/ CADASTRO da primeira amizade: "<<endl;
            cin >> id1;
            cout << "Escreva o id p/ CADASTRO da segunda amizade: "<<endl;
            cin >> id2;
            cout << endl;
            
            Pessoa p = arvore->Buscar(id1);
            Pessoa p2 = arvore->Buscar(id2);
            
            if( arvore->Buscar(id1).id != -1 && arvore->Buscar(id2).id != -1)
            {
                p.CadastrarAmizade(arvore,id1,id2);
                cout << "Amizade(s) de  "<< id1 << " " << p.nome << endl;
                cout << endl;
                p.amizades->Imprime();
                cout << endl;
                cout << "Amizade(s) de "<< id2 << " " << p2.nome <<endl;
                cout << endl;
                p2.amizades->Imprime();
            }
            else
                cout << "Um ou os dois dos id(s) nao esta(o) no sistema!" <<endl;
            
                        
        }
        else if(opcao == "CONSULTAR" || opcao == "consultar")
        {
            int id1, id2;
            cout << endl;
            cout << "Primeiro Id p/ CONSULTAR AMIZADE: "<<endl;
            cin >> id1;
            cout << "Segundo Id p/ CONSULTAR AMIZADE: "<<endl;
            cin >> id2;
            
            Pessoa p = arvore->Buscar(id1);
            
            if( arvore->Buscar(id1).id != -1 && arvore->Buscar(id2).id != -1)
            {
                if(p.ConsultarAmizade(id1,id2,arvore))
                    cout << endl <<"Possui amizade entre o id " << id1 <<" e " <<id2 << endl;
                else
                    cout << endl <<"Nao possui amizade entre os dois id's!" << endl;
            }
            else
                cout << "Um ou os dois dos id(s) nao esta(o) no sistema!" <<endl;
                     
        }
        else if(opcao == "REAMIZADE" || opcao == "reamizade")
        {
            int id1, id2;
            cout << endl;
            cout << "Escreva o primeiro id p/ REMOVER a amizade: "<<endl;
            cin >> id1;
            cout << "Escreva o segundo id p/ REMOVER a amizade: "<<endl;
            cin >> id2;
            
            Pessoa p = arvore->Buscar(id1);
            Pessoa p2 = arvore->Buscar(id2);
          if( arvore->Buscar(id1).id != -1 && arvore->Buscar(id2).id != -1) 
          { 
                if(p.ConsultarAmizade(id1,id2,arvore))
                {
                    p.amizades->Remover(id2);
                    p2.amizades->Remover(id1);
                    cout << "Amizade entre "<< p.nome <<" e "<< p2.nome <<" removida!" <<endl;
                }
                else
                    cout << "Nao possui amizade!" <<endl;
           }
           else
                cout << "Um ou os dois dos id(s) nao esta(o) no sistema!" <<endl;
                
        } 
        cout << endl;
        cout << endl;
        cout << "ESCREVA ALGUMA OPCAOO: " << endl;
        cout << endl;
        cout << "- INSERIR" << endl;
        cout << "- BUSCAR" << endl;
        cout << "- REMOVER" << endl;
        cout << "- IMPRIMIR" << endl;
        cout << "- P/ CADASTRAR AMIZADE escreva CADASTRAR/cadastrar" << endl;
        cout << "- P/ CONSULTAR AMIZADE escreva CONSULTAR/consultar" << endl;
        cout << "- P/ REMOVER AMIZADE escreva REAMIZADE/reamizade" << endl;
        cout << "- SAIR" <<endl;
        cout << endl;
        cout << "___________________________________________________________" << endl;
		cin >> opcao;
	}
}
