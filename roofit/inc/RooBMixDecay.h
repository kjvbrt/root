/*****************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: RooFitCore
 *    File: $Id: RooBMixDecay.rdl,v 1.3 2001/10/17 05:15:06 verkerke Exp $
 * Authors:
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu
 * History:
 *   05-Jun-2001 WV Created initial version
 *
 * Copyright (C) 2001 University of California
 *****************************************************************************/
#ifndef ROO_BMIX_DECAY
#define ROO_BMIX_DECAY

#include "RooFitCore/RooConvolutedPdf.hh"
#include "RooFitCore/RooRealProxy.hh"
#include "RooFitCore/RooCategoryProxy.hh"

class RooBMixDecay : public RooConvolutedPdf {
public:

  enum DecayType { SingleSided, DoubleSided, Flipped };

  // Constructors, assignment etc
  inline RooBMixDecay() { }
  RooBMixDecay(const char *name, const char *title, 
	       RooRealVar& t, RooAbsCategory& tag,
	       RooAbsReal& tau, RooAbsReal& dm,
	       RooAbsReal& mistag, const RooResolutionModel& model, 
	       DecayType type=DoubleSided) ;

  RooBMixDecay(const RooBMixDecay& other, const char* name=0);
  virtual TObject* clone(const char* newname) const { return new RooBMixDecay(*this,newname) ; }
  virtual ~RooBMixDecay();

  virtual Double_t coefficient(Int_t basisIndex) const ;

  virtual Int_t getCoefAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars) const ;
  virtual Double_t coefAnalyticalIntegral(Int_t coef, Int_t code) const ;

  Int_t getGenerator(const RooArgSet& directVars, RooArgSet &generateVars) const;
  void generateEvent(Int_t code);
  
protected:

  DecayType        _type ;
  RooRealProxy     _mistag ;
  RooCategoryProxy _tag ;
  RooRealProxy     _tau ;
  RooRealProxy     _dm ;
  RooRealProxy     x ;
  Int_t _basisExp ;
  Int_t _basisCos ;

  ClassDef(RooBMixDecay,1) // B Mixing decay PDF
};

#endif
