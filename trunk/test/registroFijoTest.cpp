#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "registroFijo.h"
#include "registro.h"
#include "gtest/gtest.h"


TEST(RegistroFijo, Crear) {
    std::string idTst = "R1";
	bool ocupadoTst = true;
	int longitudTst = 512;

	RegistroFijo *reg = new RegistroFijo(idTst, ocupadoTst, longitudTst);

    ASSERT_EQ(reg->getIdentificador(), idTst);
    ASSERT_EQ(reg->estaOcupado(), ocupadoTst);
    ASSERT_EQ(reg->getLongitud(), longitudTst);
}
