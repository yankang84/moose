/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "CheckCurrentExecAux.h"

template <>
InputParameters
validParams<CheckCurrentExecAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

CheckCurrentExecAux::CheckCurrentExecAux(const InputParameters & parameters)
  : AuxKernel(parameters), _problem(*parameters.get<FEProblemBase *>("_fe_problem_base"))
{
}

Real
CheckCurrentExecAux::computeValue()
{
  return _problem.getCurrentExecuteOnFlag();
}
