#ifndef GAPHEATTRANSFER_H
#define GAPHEATTRANSFER_H

#include "IntegratedBC.h"

//Forward Declarations
class GapHeatTransfer;

template<>
InputParameters validParams<GapHeatTransfer>();

class GapHeatTransfer : public IntegratedBC
{
public:

  GapHeatTransfer(const std::string & name, InputParameters parameters);

  virtual ~GapHeatTransfer(){}

protected:
/**
 * Generic gap heat transfer model, with h_gap =  h_conduction + h_contact + h_radiation
 */

  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);
  virtual Real gapLength() const;
  virtual Real dgapLength(Real normalComponent) const;

  virtual Real computeSlaveFluxContribution(Real grad_t);

  bool _quadrature;

  NumericVector<Number> * _slave_flux;

  const MaterialProperty<Real> & _gap_conductance;
  const MaterialProperty<Real> & _gap_conductance_dT;

  const Real _min_gap;
  const Real _max_gap;

  Real _gap_temp;
  Real _gap_distance;

  bool _has_info;

//private:
  void computeGapTempAndDistance();

  const bool _xdisp_coupled;
  const bool _ydisp_coupled;
  const bool _zdisp_coupled;

  const unsigned int _xdisp_var;
  const unsigned int _ydisp_var;
  const unsigned int _zdisp_var;

  const VariableValue & _gap_distance_value;
  const VariableValue & _gap_temp_value;

  PenetrationLocator * _penetration_locator;
  const NumericVector<Number> * & _serialized_solution;
  DofMap & _dof_map;
  const bool _warnings;
};

#endif //GAPHEATTRANSFER_H
