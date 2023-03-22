#include <systemc.h>

using namespace sc_core;

class fir : public sc_module {
  public:
    sc_in< bool > clk;
    sc_in< bool > rst;
    sc_in< sc_int<16> > inp;
    sc_in< sc_int<16> > outp;

    void fir_main(void);

    fir(sc_module_name name) : sc_module(name) {
      SC_CTHREAD(fir_main, clk.pos());
      reset_signal_is(rst, true);
    }
}
