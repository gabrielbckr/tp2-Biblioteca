#ifndef _ITEM_EMPRESTIMO_H__
#define _ITEM_EMPRESTIMO_H__

#include "Date.hpp"
#include "Livro.hpp"
#include <string>
#include <iostream>

class ItemEmprestimo {
    Date dataDevolucao; // data da devolucao
    Livro* livro; // referência para o livro emprestado
  public:
    ItemEmprestimo();
    ItemEmprestimo(Livro L ) : dataDevolucao("01/01/1900"), livro(&L) {} // constroi um ItemEmprestimo
    void atualizarDataDev(const string& Data = ""); // atualiza data de devolucao (default = data de hoje)
    const Date pegarDataDev() const; // retorna data de devolucao
    bool operator== (const ItemEmprestimo& IE);
    bool operator==(Livro& L){return *livro == L;}
    bool isEqualTo (const ItemEmprestimo& IE);
    ItemEmprestimo& operator= (const ItemEmprestimo& IE);
    ItemEmprestimo& operator++(int){livro++; return *this;}
    ItemEmprestimo& operator--(int){livro--; return *this;}
    bool  operator==(Livro& L){return *livro == L;}
    bool  operator==(ItemEmprestimo& I){return ((*livro == *I.livro) && (dataDevolucao == I.dataDevolucao));}
    friend std::ostream& operator<< (std::ostream& out, const ItemEmprestimo& IE);
    friend std::istream& operator>> (std::istream& in, ItemEmprestimo& IE);
    ~ItemEmprestimo(); // destroi o ItemEmprestimo
};

#endif
