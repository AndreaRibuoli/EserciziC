#include <iostream>
#include <string>

using namespace std;

class Azione {
  private:
    string nome;    
  public:    
    void setName(string n) { nome=n; }
    virtual string dettagli() = 0;  
    void debug() {
        cout << "dettagli(" << nome << "): " << dettagli() << "\n";
    }
};

class Tweet : public Azione {
  private:
    string messaggio;    
  public:
    void setMessage(string n, string m) { 
        messaggio=m; 
        setName(n); 
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
    void setMessage(string n, string m, string d) { 
        messaggio=m; 
        destinatario=d; 
        setName(n); 
    }
    string dettagli() { 
        string risultato = destinatario + "(" + destinatario + ")";
        return risultato; }  
};

int main() {
   Tweet t; 
   t.setMessage("tweet", "Mi dispiace se oggi è stata molto pesante la lezione!"); 
   Email e;
   e.setMessage("email", "vedi tweet che ti ho inviato", "andrea.ribuoli@yahoo.com");
   t.debug();
   e.debug(); 
}