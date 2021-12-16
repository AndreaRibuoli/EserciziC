#include <iostream>
#include <string>

using namespace std;

class Azione {
  private:
    string nome;    
  public:    
    Azione(string n) { nome=n; }
    virtual string dettagli() = 0;  
    void debug() {
        cout << "dettagli(" << nome << "): " << dettagli() << "\n";
    }
};

class Tweet : public Azione {
  private:
    string messaggio;    
  public:
    using Azione::Azione;
    Tweet(string n, string m) : Tweet(n) { messaggio=m; }
    void setMessage(string n, string m) { 
        messaggio=m; 
    }
    string dettagli() { 
        string risultato = messaggio;
        return risultato; }  
};

class Email : public Azione {
  private:
    string messaggio;
    string destinatario;
  public:
    using Azione::Azione;
    Email(string n, string m, string d) : Email(n) { messaggio=m; destinatario=d; }
    void setMessage(string n, string m, string d) { 
        messaggio=m; 
        destinatario=d; 
    }
    string dettagli() { 
        string risultato = messaggio + "(" + destinatario + ")";
        return risultato; }  
};

int main() {
   Tweet t = Tweet(string("a tweet"), "Mi dispiace se oggi è stata molto pesante la lezione!"); 
   Email e = Email(string("an email"), "vedi tweet che ti ho inviato", "andrea.ribuoli@yahoo.com");
   t.debug();
   e.debug(); 
}
