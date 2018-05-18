#include <iostream>

using namespace std;


template <class T, class U>
class No
{
public:
	No(T ch, U co);
	T id;
	U conteudo;
	No * esquerda, * direita;
};

template <class T, class U>
No<T, U>::No(T ch, U co)
{
	id = ch;
	conteudo = co;
	esquerda = NULL;
	direita = NULL;
}



template <class T, class U>
class Arvore
{
public:
	No<T, U> * raiz;
	

	Arvore();
	void Arvore<T, U>::Inserir(T id, U conteudo);
	void Arvore<T, U>::InserirRecursivo(No<T, U> * & anda, T id, U conteudo);
	U Remover(T id);
	U RemoverRecursivo(No<T, U> * & anda, T id);
	U Arvore<T, U>::Buscar(T id);
	U Arvore<T, U>::BuscarRecursivo(No<T, U> * anda, T id);
  	void Imprime();
	void ImprimeRec(No<T, U> * x);
};

template <class T, class U>
Arvore<T, U>::Arvore()
{
	raiz = NULL;
	
}

template <class T, class U>
void Arvore<T, U>::Inserir(T id, U conteudo)
{
	
	InserirRecursivo(raiz, id, conteudo);
}




template <class T, class U>
void Arvore<T, U>::InserirRecursivo(No<T, U> * & anda, T id, U conteudo)
{
	if(anda == NULL)
	{
		No<T, U> * novo = new No<T, U>(id, conteudo);

		anda = novo;
	}

	if(id == anda->id)
		return;

	if(id < anda->id)
		InserirRecursivo(anda->esquerda, id, conteudo);

	if(id > anda->id)
		InserirRecursivo(anda->direita, id, conteudo);
}



template <class T, class U>
U Arvore<T, U>::Buscar(T id)
{
	return BuscarRecursivo(raiz, id);
}

template <class T, class U>
U Arvore<T, U>::BuscarRecursivo(No<T, U> * anda, T id)
{
	if(anda == NULL)
		return U();

	if(id == anda->id)
		return anda->conteudo;

	if(id < anda->id)
		return BuscarRecursivo(anda->esquerda, id);

	if(id > anda->id)
		return BuscarRecursivo(anda->direita, id);
}

template <class T, class U>
U Arvore<T, U>::Remover(T id)
{
	return RemoverRecursivo(raiz, id);
}

template <class T, class U>
U Arvore<T, U>::RemoverRecursivo(No<T, U> * & anda, T id)
{
	if(anda == NULL)
		return U();

    if(id == anda->id)
	{
		U conteudo = anda->conteudo;
		//Caso 3: 2 Filhos
        if(anda->esquerda != NULL && anda->direita != NULL)	
		{
			//Encontrar maior da esquerda de anda
			No<T, U> * ME = anda->esquerda;
			while(ME->direita != NULL)
				ME = ME->direita;

			T idME = ME->id;
			anda->conteudo = RemoverRecursivo(anda->esquerda, ME->id);
			anda->id = idME;
		}
        else
		{
			No<T, U> * novoanda;
			//Caso 1: NÃ³ Folha
			if(anda->esquerda == NULL && anda->direita == NULL)	
			{
				novoanda = NULL;
			}
			//Caso 2: 1 Filho (direita)
			else if(anda->esquerda == NULL && anda->direita != NULL)
			{
			
				novoanda = anda->direita;
            }
			//Caso 2: 1 Filho (esquerda)
			else if(anda->direita == NULL && anda->esquerda != NULL)
			{
				novoanda = anda->esquerda;
			}

			delete anda;
			anda = novoanda;
		}

		return conteudo;
	}
	if(id < anda->id)
		return RemoverRecursivo(anda->esquerda, id);
	else if(id > anda->id)
		return RemoverRecursivo(anda->direita, id);
}

                                                                             

template <class T, class U>
void Arvore<T, U>::Imprime()
{
	ImprimeRec(raiz);
}

template <class T, class U>
void Arvore<T, U>::ImprimeRec(No<T, U> * x)
{
	if(x == NULL)
		return;	

	ImprimeRec(x->esquerda);
	cout << x->id << " "  << x->conteudo.nome << endl;
    ImprimeRec(x->direita);
}
