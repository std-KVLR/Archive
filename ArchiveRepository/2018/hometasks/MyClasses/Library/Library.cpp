#include "Library_book.h"
#include <stdexcept>

namespace Library_Classes
{
    void Library::add_patron(const Patron &this_patron)
    {
         if(!(this_patron.is_patron_pay())) throw(nopay_patron);
         patrons.push_back(this_patron);
    }
    Patron& Library::search_patron(const str &card_number)
    {
        for(auto &i : patrons){
            if(i.get_cardNum() == card_number){
                return i;
            }
        }
        throw(ndef_patron);
    }
    Library_book& Library::search_book(const str &ISBN)
    {
        for(auto &i : books){
            if(i.get_isbn() == ISBN){
                return i;
            }
        }
        throw(ndef_book);
    }
    void Library::create_trans(const str &ISBN, const str &card_NUM)
    {

        try
        {
            Patron temp_patron = search_patron(card_NUM);
            if(!(temp_patron.is_patron_pay())) throw(nopay_patron);
            Library_book temp_book = search_book(ISBN);
            Date temp_date;
            std::cin >> temp_date;
            Transaction temp_trans{search_book(ISBN), temp_patron, temp_date};
            transactions.push_back(temp_trans);
        }
        catch(short err)
        {
            switch(err)
            {
            case -1:
                throw std::runtime_error("error: this patron is not payed");
            case -2:
                throw std::runtime_error("error: patron is not defined");
            case -3:
                throw std::runtime_error("error: book is not defined");
            }
        }

    }
    std::vector<Patron> Library::debtors()
    {
        std::vector<Patron> deb_v;
        for(auto& p : patrons){
                if(!p.is_patron_pay()) deb_v.push_back(p);
        }
        return deb_v;
    }
}
