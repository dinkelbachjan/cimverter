/*
 * Transformer.h
 *
 */

#ifndef SRC_MODELICAWORKSHOP_MODPOWERSYSTEMS_PHASORSINGLEPHASE_TRANSFORMERS_TRANSFORMER_H_
#define SRC_MODELICAWORKSHOP_MODPOWERSYSTEMS_PHASORSINGLEPHASE_TRANSFORMERS_TRANSFORMER_H_

#include "../../../ModBaseClass.h"
#include "../Connections/BusBar.h"
#include <cmath>
typedef ModPowerSystems::PhasorSinglePhase::Connections::BusBar BusBar;

using namespace ModelicaWorkshop;

namespace ModPowerSystems {

namespace PhasorSinglePhase {

namespace Transformers {

class Transformer : public ModBaseClass {
 public:
  Transformer();
  Transformer(const Transformer &);
  Transformer& operator=(const Transformer &);
  virtual ~Transformer();

  void set_tap_pos(double tap_pos){
    this->tap_pos = tap_pos;
  }

  void set_Vnom1(double Vnom1) {
    this->_Vnom1 = Vnom1;
  };
  double Vnom1() const {
    return _Vnom1;
  };

  void set_Vnom2(double Vnom2) {
    this->_Vnom2 = Vnom2;
  };
  double Vnom2() const {
    return _Vnom2;
  };

  void set_Sr(double Sr) {
    this->_Sr = Sr;
  };
  double Sr() const {
    return _Sr;
  };

  void set_URr(double URr) {
    this->_URr = URr;
  };
  double URr() const {
    return _URr;
  };
  void calc_URr() {
    _URr = _r*(_Sr*100)/(_Vnom1*_Vnom1);
  };

  void set_Ukr(double Ukr) {
    this->_Ukr = Ukr;
  };
  double Ukr() const {
    return _Ukr;
  };
  void calc_Ukr() {
    this->calc_z();
    _Ukr = _z*(_Sr*100)/(_Vnom1*_Vnom1);
  };

  void set_Vnom1_displayUnit(modelicaUnit Vnom1_displayUnit) {
    this->_Vnom1_displayUnit = Vnom1_displayUnit;
  }
  ;
  modelicaUnit Vnom1_displayUnit() const {
    return _Vnom1_displayUnit;
  };

  void set_Vnom2_displayUnit(modelicaUnit Vnom2_displayUnit) {
    this->_Vnom2_displayUnit = Vnom2_displayUnit;
  };
  modelicaUnit Vnom2_displayUnit() const {
    return _Vnom2_displayUnit;
  };

  void set_Sr_displayUnit(modelicaUnit Sr_displayUnit) {
    this->_Sr_displayUnit = Sr_displayUnit;
  };
  modelicaUnit Sr_displayUnit() const {
    return _Sr_displayUnit;
  };

  void set_z(double z) {
    this->_z = z;
  };
  double z() const {
    return _z;
  };
  void calc_z() {
    _z = sqrt(_x*_x + _r*_r);
  };

  void set_r(double r) {
    this->_r = r;
  };
  double r() const {
    return _r;
  };

  void set_x(double x) {
    this->_x = x;
  };
  double x() const {
    return _x;
  };

  void set_b(double b) {
    this->_b = b;
  };
  double b() const {
    return _b;
  };

  void set_g(double g) {
    this->_g = g;
  };
  double g() const {
    return _g;
  };

  bool set_template_values(ctemplate::TemplateDictionary *dictionary) override;

  BusBar* getBus1()const {
    return this->bus1;

  }
  BusBar* getBus2()const {
      return this->bus2;

  }
  void setBus1(BusBar* bus){
    this->bus1 = bus;
    bus1Initialized = true;
  }
  void setBus2(BusBar* bus){
      this->bus2 = bus;
      bus2Initialized = true;
  }

  void setBus(BusBar* bus){
    if(this->bus1Initialized == false){
      setBus1(bus);
      bus1Initialized = true;
    }else{
      setBus2(bus);
      bus2Initialized = true;
    }
  }

 private:
  BusBar* bus1;
  bool bus1Initialized = false;
  BusBar* bus2;
  bool bus2Initialized = false;
  double _Vnom1 = 0;  //primary voltage level
  double _Vnom2 = 0;  //secondary voltage level
  double _Sr = 0;  //rated apparent power
  double _URr = 0.31;  //copper losses
  double _Ukr = 12.04;  //short circuit voltage

  double _z = 1;
  double _r = 0;
  double _x = 0;
  double _b = 0;
  double _g = 0;

  double tap_pos = 0;
  double tap_step = 0.1;

  modelicaUnit _Vnom1_displayUnit = modelicaUnit::V;
  modelicaUnit _Vnom2_displayUnit = modelicaUnit::V;
  modelicaUnit _Sr_displayUnit = modelicaUnit::W;
};

} /* namespace Transformers */

} /* namespace PhasorSinglePhase */

} /* namespace ModPowerSystems */

#endif /* SRC_MODELICAWORKSHOP_MODPOWERSYSTEMS_PHASORSINGLEPHASE_TRANSFORMERS_TRANSFORMER_H_ */
