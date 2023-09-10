#ifndef PRAX10_H
#define PRAX10_H

template <typename T>
class Magasin{
public:
  Magasin();                  // vaikekonstruktor
  ~Magasin();                           // destruktor
 
  Magasin(Magasin& m);            // koopiakonstruktor
  Magasin& operator = (const Magasin& m); // koopia omistamise (''copy assignment'') operaator
  void push(T& element);        // lisa element magasini
  T pop();                            // võta element magasinist välja
  bool isEmpty() const;               // kas magasin on tühi?
  void tryki();                       // kuvab magasini elemendid ekraanile
private:
  // Siseklass
  class Tipp{
  public:
    Tipp(const T& liige) : m_liige{liige} {} // Tipp konstruktor
    T m_liige;            // Tipus hoitav objekt
    Tipp* m_jargmine{};   // viit järgmisele tipule
  };
 
  Tipp* m_pea{};     // viit magasini otsale
};

#endif