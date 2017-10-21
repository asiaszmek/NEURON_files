/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define pbar _p[0]
#define i _p[1]
#define p _p[2]
#define n _p[3]
#define h _p[4]
#define c _p[5]
#define ica _p[6]
#define cai _p[7]
#define cao _p[8]
#define Dn _p[9]
#define Dh _p[10]
#define Dc _p[11]
#define v _p[12]
#define _g _p[13]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _ion_dicadv	*_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_Boltz_m1(void);
 static void _hoc_BorgMod_tau(void);
 static void _hoc_Boltzmann(void);
 static void _hoc_efun(void);
 static void _hoc_ghk(void);
 static void _hoc_ngate_adjust(void);
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_cal0", _hoc_setdata,
 "Boltz_m1_cal0", _hoc_Boltz_m1,
 "BorgMod_tau_cal0", _hoc_BorgMod_tau,
 "Boltzmann_cal0", _hoc_Boltzmann,
 "efun_cal0", _hoc_efun,
 "ghk_cal0", _hoc_ghk,
 "ngate_adjust_cal0", _hoc_ngate_adjust,
 "rates_cal0", _hoc_rates,
 0, 0
};
#define Boltz_m1 Boltz_m1_cal0
#define BorgMod_tau BorgMod_tau_cal0
#define Boltzmann Boltzmann_cal0
#define efun efun_cal0
#define ghk ghk_cal0
 extern double Boltz_m1( _threadargsprotocomma_ double , double , double );
 extern double BorgMod_tau( _threadargsprotocomma_ double , double , double , double , double , double , double , double );
 extern double Boltzmann( _threadargsprotocomma_ double , double , double );
 extern double efun( _threadargsprotocomma_ double );
 extern double ghk( _threadargsprotocomma_ double , double , double );
 /* declare global and static user variables */
 static int _thread1data_inuse = 0;
static double _thread1data[11];
#define _gth 0
#define K_c K_c_cal0
 double K_c = 0.001;
#define gates_n gates_n_cal0
 double gates_n = 1;
#define hill_c hill_c_cal0
 double hill_c = 1;
#define inf_h_cal0 _thread1data[0]
#define inf_h _thread[_gth]._pval[0]
#define inf_c_cal0 _thread1data[1]
#define inf_c _thread[_gth]._pval[1]
#define inf_n_cal0 _thread1data[2]
#define inf_n _thread[_gth]._pval[2]
#define n_gate n_gate_cal0
 double n_gate = 2;
#define needAdj_cal0 _thread1data[3]
#define needAdj _thread[_gth]._pval[3]
#define shat_h shat_h_cal0
 double shat_h = 10;
#define slope_h slope_h_cal0
 double slope_h = 10;
#define slp_adj_cal0 _thread1data[4]
#define slp_adj _thread[_gth]._pval[4]
#define slopeA_n_cal0 _thread1data[5]
#define slopeA_n _thread[_gth]._pval[5]
#define slope_n slope_n_cal0
 double slope_n = -4.98;
#define tau_h_cal0 _thread1data[6]
#define tau_h _thread[_gth]._pval[6]
#define tau_c_cal0 _thread1data[7]
#define tau_c _thread[_gth]._pval[7]
#define tau_n_cal0 _thread1data[8]
#define tau_n _thread[_gth]._pval[8]
#define tau0_c tau0_c_cal0
 double tau0_c = 10;
#define tauA_c tauA_c_cal0
 double tauA_c = 10;
#define tauDv_h tauDv_h_cal0
 double tauDv_h = 0;
#define tauF_h tauF_h_cal0
 double tauF_h = 0;
#define tau0_h tau0_h_cal0
 double tau0_h = 0;
#define tauG_h tauG_h_cal0
 double tauG_h = 0.5;
#define tauA_h tauA_h_cal0
 double tauA_h = 200;
#define tau0_n tau0_n_cal0
 double tau0_n = 0.06;
#define tauF_n tauF_n_cal0
 double tauF_n = 0;
#define tauG_n tauG_n_cal0
 double tauG_n = 0.32;
#define tauDv_n tauDv_n_cal0
 double tauDv_n = 0;
#define tauA_n tauA_n_cal0
 double tauA_n = 0.75;
#define vhat_h vhat_h_cal0
 double vhat_h = -59.5;
#define vhalf_h vhalf_h_cal0
 double vhalf_h = 1000;
#define v5_adj_cal0 _thread1data[9]
#define v5_adj _thread[_gth]._pval[9]
#define vhalfA_n_cal0 _thread1data[10]
#define vhalfA_n _thread[_gth]._pval[10]
#define vhalf_n vhalf_n_cal0
 double vhalf_n = -15;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vhalf_n_cal0", "mV",
 "slope_n_cal0", "mV",
 "vhalfA_n_cal0", "mV",
 "slopeA_n_cal0", "mV",
 "v5_adj_cal0", "mV",
 "slp_adj_cal0", "mV",
 "tauA_n_cal0", "ms",
 "tauDv_n_cal0", "mV",
 "tau0_n_cal0", "ms",
 "slope_h_cal0", "mV",
 "vhat_h_cal0", "mV",
 "shat_h_cal0", "mV",
 "tauA_h_cal0", "ms",
 "tau0_h_cal0", "ms",
 "K_c_cal0", "mM",
 "tauA_c_cal0", "ms",
 "tau0_c_cal0", "ms",
 "tau_n_cal0", "ms",
 "tau_c_cal0", "ms",
 "tau_h_cal0", "ms",
 "pbar_cal0", "cm/s",
 "i_cal0", "mA/cm2",
 "p_cal0", "cm/s",
 0,0
};
 static double c0 = 0;
 static double delta_t = 0.01;
 static double h0 = 0;
 static double n0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "gates_n_cal0", &gates_n_cal0,
 "vhalf_n_cal0", &vhalf_n_cal0,
 "slope_n_cal0", &slope_n_cal0,
 "needAdj_cal0", &needAdj_cal0,
 "vhalfA_n_cal0", &vhalfA_n_cal0,
 "slopeA_n_cal0", &slopeA_n_cal0,
 "v5_adj_cal0", &v5_adj_cal0,
 "slp_adj_cal0", &slp_adj_cal0,
 "n_gate_cal0", &n_gate_cal0,
 "tauA_n_cal0", &tauA_n_cal0,
 "tauDv_n_cal0", &tauDv_n_cal0,
 "tauG_n_cal0", &tauG_n_cal0,
 "tauF_n_cal0", &tauF_n_cal0,
 "tau0_n_cal0", &tau0_n_cal0,
 "vhalf_h_cal0", &vhalf_h_cal0,
 "slope_h_cal0", &slope_h_cal0,
 "vhat_h_cal0", &vhat_h_cal0,
 "shat_h_cal0", &shat_h_cal0,
 "tauA_h_cal0", &tauA_h_cal0,
 "tauG_h_cal0", &tauG_h_cal0,
 "tau0_h_cal0", &tau0_h_cal0,
 "tauF_h_cal0", &tauF_h_cal0,
 "tauDv_h_cal0", &tauDv_h_cal0,
 "hill_c_cal0", &hill_c_cal0,
 "K_c_cal0", &K_c_cal0,
 "tauA_c_cal0", &tauA_c_cal0,
 "tau0_c_cal0", &tau0_c_cal0,
 "inf_n_cal0", &inf_n_cal0,
 "tau_n_cal0", &tau_n_cal0,
 "inf_c_cal0", &inf_c_cal0,
 "tau_c_cal0", &tau_c_cal0,
 "inf_h_cal0", &inf_h_cal0,
 "tau_h_cal0", &tau_h_cal0,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"cal0",
 "pbar_cal0",
 0,
 "i_cal0",
 "p_cal0",
 0,
 "n_cal0",
 "h_cal0",
 "c_cal0",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	pbar = 0.000241;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cal0_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 2);
  _extcall_thread = (Datum*)ecalloc(1, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
  _thread1data_inuse = 0;
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 14, 5);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cal0 /home/neuro/Documents/from_axon/ca1n1-mod/x86_64/cal0.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96520.0;
 static double R = 8.3134;
static int _reset;
static char *modelname = "CaL channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int ngate_adjust(_threadargsprotocomma_ double, double, double);
static int rates(_threadargsprotocomma_ double, double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[3], _dlist1[3];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v , cai ) ;
   Dn = ( inf_n - n ) / tau_n ;
   Dh = ( inf_h - h ) / tau_h ;
   Dc = ( inf_c - c ) / tau_c ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargscomma_ v , cai ) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_n )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_h )) ;
 Dc = Dc  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_c )) ;
 return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargscomma_ v , cai ) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_n)))*(- ( ( ( inf_n ) ) / tau_n ) / ( ( ( ( - 1.0) ) ) / tau_n ) - n) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_h)))*(- ( ( ( inf_h ) ) / tau_h ) / ( ( ( ( - 1.0) ) ) / tau_h ) - h) ;
    c = c + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_c)))*(- ( ( ( inf_c ) ) / tau_c ) / ( ( ( ( - 1.0) ) ) / tau_c ) - c) ;
   }
  return 0;
}
 
static int  rates ( _threadargsprotocomma_ double _lv , double _lcai ) {
   if ( needAdj > 0.0 ) {
     needAdj = 0.0 ;
     ngate_adjust ( _threadargscomma_ gates_n , vhalf_n , slope_n ) ;
     vhalfA_n = v5_adj ;
     slopeA_n = slp_adj ;
     }
   inf_n = Boltzmann ( _threadargscomma_ _lv , vhalf_n , slope_n ) ;
   tau_n = BorgMod_tau ( _threadargscomma_ _lv , vhalf_n , slope_n , tau0_n , tauA_n , tauG_n , tauF_n , tauDv_n ) ;
   inf_h = 1.0 / ( 1.0 + exp ( ( _lv - vhalf_h ) / slope_h ) ) ;
   tau_h = tau0_h + tauA_h * 4.0 * sqrt ( tauG_h * ( 1.0 - tauG_h ) ) / ( exp ( - ( _lv - vhalf_h ) / slope_h * ( 1.0 - tauG_h ) ) + exp ( ( _lv - vhalf_h ) / slope_h * tauG_h ) ) ;
   inf_c = 1.0 / ( 1.0 + pow( ( _lcai / K_c ) , hill_c ) ) ;
   tau_c = tau0_c + tauA_c / ( 1.0 + pow( ( _lcai / K_c ) , hill_c ) ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double Boltzmann ( _threadargsprotocomma_ double _lv , double _lv5 , double _ls ) {
   double _lBoltzmann;
 _lBoltzmann = 1.0 / ( 1.0 + exp ( ( _lv - _lv5 ) / _ls ) ) ;
   
return _lBoltzmann;
 }
 
static void _hoc_Boltzmann(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  Boltzmann ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
}
 
double BorgMod_tau ( _threadargsprotocomma_ double _lv , double _lv5 , double _ls , double _ltau0 , double _ltauA , double _ltauG , double _ltauF , double _ltauDv ) {
   double _lBorgMod_tau;
 double _lkc , _lkr , _lDv , _lwr , _lkf ;
 _lDv = ( _lv - ( _lv5 + _ltauDv ) ) ;
   _lkf = pow( 10.0 , _ltauF ) ;
   _lBorgMod_tau = _ltau0 + _ltauA * 4.0 * sqrt ( _ltauG * ( 1.0 - _ltauG ) ) / ( exp ( - _lDv * ( 1.0 - _ltauG ) * _lkf / _ls ) + exp ( _lDv * _ltauG * _lkf / _ls ) ) ;
   
return _lBorgMod_tau;
 }
 
static void _hoc_BorgMod_tau(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  BorgMod_tau ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) , *getarg(5) , *getarg(6) , *getarg(7) , *getarg(8) );
 hoc_retpushx(_r);
}
 
double ghk ( _threadargsprotocomma_ double _lv , double _lci , double _lco ) {
   double _lghk;
 double _lz , _leci , _leco ;
 _lz = ( 1e-3 ) * 2.0 * FARADAY * _lv / ( R * ( celsius + 273.15 ) ) ;
   _leco = _lco * efun ( _threadargscomma_ _lz ) ;
   _leci = _lci * efun ( _threadargscomma_ - _lz ) ;
   _lghk = ( .001 ) * 2.0 * FARADAY * ( _leci - _leco ) ;
   
return _lghk;
 }
 
static void _hoc_ghk(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ghk ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
}
 
double efun ( _threadargsprotocomma_ double _lz ) {
   double _lefun;
 if ( fabs ( _lz ) < 1e-4 ) {
     _lefun = 1.0 - _lz / 2.0 ;
     }
   else {
     _lefun = _lz / ( exp ( _lz ) - 1.0 ) ;
     }
   
return _lefun;
 }
 
static void _hoc_efun(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  efun ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double Boltz_m1 ( _threadargsprotocomma_ double _lx , double _lv5 , double _ls ) {
   double _lBoltz_m1;
 _lBoltz_m1 = _ls * log ( 1.0 / _lx - 1.0 ) + _lv5 ;
   
return _lBoltz_m1;
 }
 
static void _hoc_Boltz_m1(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  Boltz_m1 ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
}
 
static int  ngate_adjust ( _threadargsprotocomma_ double _lng , double _lvh , double _lslp ) {
   double _lx1 , _lx2 , _lv1 , _lv2 ;
 _lx1 = 0.3 ;
   _lx2 = 0.7 ;
   _lv1 = Boltz_m1 ( _threadargscomma_ _lx1 , _lvh , _lslp ) ;
   _lv2 = Boltz_m1 ( _threadargscomma_ _lx2 , _lvh , _lslp ) ;
   slp_adj = ( _lv2 - _lv1 ) / ( log ( pow( ( 1.0 / _lx2 ) , ( 1.0 / _lng ) ) - 1.0 ) - log ( pow( ( 1.0 / _lx1 ) , ( 1.0 / _lng ) ) - 1.0 ) ) ;
   v5_adj = _lv1 - slp_adj * log ( 1.0 / pow( _lx1 , ( 1.0 / _lng ) ) - 1.0 ) ;
    return 0; }
 
static void _hoc_ngate_adjust(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 ngate_adjust ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 3;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 3; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _thread_mem_init(Datum* _thread) {
  if (_thread1data_inuse) {_thread[_gth]._pval = (double*)ecalloc(11, sizeof(double));
 }else{
 _thread[_gth]._pval = _thread1data; _thread1data_inuse = 1;
 }
 }
 
static void _thread_cleanup(Datum* _thread) {
  if (_thread[_gth]._pval == _thread1data) {
   _thread1data_inuse = 0;
  }else{
   free((void*)_thread[_gth]._pval);
  }
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  c = c0;
  h = h0;
  n = n0;
 {
   rates ( _threadargscomma_ v , cai ) ;
   n = inf_n ;
   h = inf_h ;
   c = inf_c ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cai = _ion_cai;
  cao = _ion_cao;
 initmodel(_p, _ppvar, _thread, _nt);
 }}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   p = 0.0 ;
   p = pbar * pow( n , n_gate ) * h * c ;
   i = p * ghk ( _threadargscomma_ v , cai , cao ) ;
   ica = i ;
   }
 _current += ica;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  cai = _ion_cai;
  cao = _ion_cao;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  cai = _ion_cai;
  cao = _ion_cao;
 { {
 for (; t < _break; t += dt) {
   states(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(n) - _p;  _dlist1[0] = &(Dn) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
 _slist1[2] = &(c) - _p;  _dlist1[2] = &(Dc) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
