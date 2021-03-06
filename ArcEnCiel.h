#ifndef ARCENCIEL_H
#define ARCENCIEL_H
#include <stdint.h>
#include "Context.h"

struct Chaine {
  uint64_t idx1;    // premier indice de la chaine
  uint64_t idxT;    // dernier indice de la chaine
};

class ArcEnCiel {
    public:
      unsigned int _numero;   // numero de la table (ici 0, mais voir "Moult tables")
      unsigned int _M;        // nombre de chaines dans la table
      unsigned int _T;        // taille de chaque chaine
      Chaine* _X;     // la table elle-meme
      // Creer les M chaînes de taille T, dans le contexte ctxt
      void creer(Context ctxt, int num, int M, int T );
      // Tri _X suivant idxT.
      void trier();
      // Sauvegarde la table sur disque.
      void save( std::string name );
      // Charge en mémoire la table à partir du disque.
      void load( std::string name );
      // Recherche dichotomique dans la table
      // ( p et q sont le premier/dernier trouvé )
      bool recherche( uint64_t idx, unsigned int & p, unsigned int & q );
};
#endif // ARCENCIEL_H
