/* Include files */

#include <stddef.h>
#include "blas.h"
#include "TSE_Path_sfun.h"
#include "c63_TSE_Path.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "TSE_Path_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c63_debug_family_names[20] = { "Sfcn5i", "T5si", "DHTi",
  "h5cacul", "a", "b", "error", "h5guess", "Z", "nargin", "nargout", "f", "PRGT",
  "EFGT", "T41s", "Sfcn41", "T5s", "h5", "Sfcn5", "DHT_T" };

static const char * c63_b_debug_family_names[9] = { "T_lib", "psi_lib",
  "thetapsi_lib", "thetapsi", "nargin", "nargout", "f", "T", "Sfcn" };

static const char * c63_c_debug_family_names[10] = { "a", "b", "error",
  "SfcnGuess", "Z", "nargin", "nargout", "Sfcn", "f", "Ts" };

static const char * c63_d_debug_family_names[9] = { "b_FuelAirRatio", "TE",
  "Hia", "Hif", "nargin", "nargout", "T", "FuelAirRatio", "Hi" };

/* Function Declarations */
static void initialize_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void initialize_params_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance);
static void enable_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void disable_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_update_debugger_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance);
static void set_sim_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_st);
static void finalize_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void sf_gateway_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void mdl_start_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_chartstep_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance);
static void initSimStructsc63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance);
static real_T c63_Ts_Sfcn_f(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_Sfcn, real_T c63_b_f);
static real_T c63_Sfcn_Ts(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_b_f, real_T c63_T);
static real_T c63_gashi(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_T, real_T c63_FuelAirRatio);
static void init_script_number_translation(uint32_T c63_machineNumber, uint32_T
  c63_chartNumber, uint32_T c63_instanceNumber);
static const mxArray *c63_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData);
static real_T c63_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c63_b_DHT_T, const char_T *c63_identifier);
static real_T c63_b_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId);
static void c63_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c63_mxArrayInData, const char_T *c63_varName, void *c63_outData);
static const mxArray *c63_b_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData);
static const mxArray *c63_c_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData);
static void c63_info_helper(const mxArray **c63_info);
static const mxArray *c63_emlrt_marshallOut(const char * c63_u);
static const mxArray *c63_b_emlrt_marshallOut(const uint32_T c63_u);
static void c63_b_info_helper(const mxArray **c63_info);
static void c63_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_realmax(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_eml_scalar_eg(SFc63_TSE_PathInstanceStruct *chartInstance);
static real_T c63_interp1(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_varargin_3);
static real_T c63_interp1_work(SFc63_TSE_PathInstanceStruct *chartInstance,
  real_T c63_xi);
static void c63_StringToMethodID(SFc63_TSE_PathInstanceStruct *chartInstance);
static int32_T c63_intmin(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_b_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance);
static void c63_c_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance);
static real_T c63_b_interp1(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_varargin_1[181], real_T c63_varargin_2[181], real_T c63_varargin_3);
static void c63_flip(SFc63_TSE_PathInstanceStruct *chartInstance, real_T c63_x
                     [181], real_T c63_b_x[181]);
static const mxArray *c63_d_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData);
static int32_T c63_c_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId);
static void c63_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c63_mxArrayInData, const char_T *c63_varName, void *c63_outData);
static uint8_T c63_d_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_b_is_active_c63_TSE_Path, const char_T
  *c63_identifier);
static uint8_T c63_e_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId);
static void c63_b_flip(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_x[181]);
static void init_dsm_address_info(SFc63_TSE_PathInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc63_TSE_PathInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c63_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c63_is_active_c63_TSE_Path = 0U;
}

static void initialize_params_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c63_update_debugger_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance)
{
  const mxArray *c63_st;
  const mxArray *c63_y = NULL;
  real_T c63_hoistedGlobal;
  real_T c63_u;
  const mxArray *c63_b_y = NULL;
  real_T c63_b_hoistedGlobal;
  real_T c63_b_u;
  const mxArray *c63_c_y = NULL;
  real_T c63_c_hoistedGlobal;
  real_T c63_c_u;
  const mxArray *c63_d_y = NULL;
  real_T c63_d_hoistedGlobal;
  real_T c63_d_u;
  const mxArray *c63_e_y = NULL;
  uint8_T c63_e_hoistedGlobal;
  uint8_T c63_e_u;
  const mxArray *c63_f_y = NULL;
  c63_st = NULL;
  c63_st = NULL;
  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_createcellmatrix(5, 1), false);
  c63_hoistedGlobal = *chartInstance->c63_DHT_T;
  c63_u = c63_hoistedGlobal;
  c63_b_y = NULL;
  sf_mex_assign(&c63_b_y, sf_mex_create("y", &c63_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c63_y, 0, c63_b_y);
  c63_b_hoistedGlobal = *chartInstance->c63_Sfcn5;
  c63_b_u = c63_b_hoistedGlobal;
  c63_c_y = NULL;
  sf_mex_assign(&c63_c_y, sf_mex_create("y", &c63_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c63_y, 1, c63_c_y);
  c63_c_hoistedGlobal = *chartInstance->c63_T5s;
  c63_c_u = c63_c_hoistedGlobal;
  c63_d_y = NULL;
  sf_mex_assign(&c63_d_y, sf_mex_create("y", &c63_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c63_y, 2, c63_d_y);
  c63_d_hoistedGlobal = *chartInstance->c63_h5;
  c63_d_u = c63_d_hoistedGlobal;
  c63_e_y = NULL;
  sf_mex_assign(&c63_e_y, sf_mex_create("y", &c63_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c63_y, 3, c63_e_y);
  c63_e_hoistedGlobal = chartInstance->c63_is_active_c63_TSE_Path;
  c63_e_u = c63_e_hoistedGlobal;
  c63_f_y = NULL;
  sf_mex_assign(&c63_f_y, sf_mex_create("y", &c63_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c63_y, 4, c63_f_y);
  sf_mex_assign(&c63_st, c63_y, false);
  return c63_st;
}

static void set_sim_state_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_st)
{
  const mxArray *c63_u;
  chartInstance->c63_doneDoubleBufferReInit = true;
  c63_u = sf_mex_dup(c63_st);
  *chartInstance->c63_DHT_T = c63_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c63_u, 0)), "DHT_T");
  *chartInstance->c63_Sfcn5 = c63_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c63_u, 1)), "Sfcn5");
  *chartInstance->c63_T5s = c63_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c63_u, 2)), "T5s");
  *chartInstance->c63_h5 = c63_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c63_u, 3)), "h5");
  chartInstance->c63_is_active_c63_TSE_Path = c63_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c63_u, 4)),
     "is_active_c63_TSE_Path");
  sf_mex_destroy(&c63_u);
  c63_update_debugger_state_c63_TSE_Path(chartInstance);
  sf_mex_destroy(&c63_st);
}

static void finalize_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c63_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_f, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_PRGT, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_EFGT, 2U);
  chartInstance->c63_sfEvent = CALL_EVENT;
  c63_chartstep_c63_TSE_Path(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_TSE_PathMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_T5s, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_T41s, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_h5, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_Sfcn5, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_Sfcn41, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c63_DHT_T, 8U);
}

static void mdl_start_c63_TSE_Path(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c63_chartstep_c63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance)
{
  real_T c63_hoistedGlobal;
  real_T c63_b_hoistedGlobal;
  real_T c63_c_hoistedGlobal;
  real_T c63_d_hoistedGlobal;
  real_T c63_e_hoistedGlobal;
  real_T c63_b_f;
  real_T c63_b_PRGT;
  real_T c63_b_EFGT;
  real_T c63_b_T41s;
  real_T c63_b_Sfcn41;
  uint32_T c63_debug_family_var_map[20];
  real_T c63_Sfcn5i;
  real_T c63_T5si;
  real_T c63_DHTi;
  real_T c63_h5cacul;
  real_T c63_a;
  real_T c63_b;
  real_T c63_error;
  real_T c63_h5guess;
  real_T c63_Z;
  real_T c63_nargin = 5.0;
  real_T c63_nargout = 4.0;
  real_T c63_b_T5s;
  real_T c63_b_h5;
  real_T c63_b_Sfcn5;
  real_T c63_b_DHT_T;
  real_T c63_x;
  real_T c63_b_x;
  real_T c63_A;
  real_T c63_c_x;
  real_T c63_d_x;
  real_T c63_e_x;
  real_T c63_y;
  real_T c63_b_A;
  real_T c63_B;
  real_T c63_f_x;
  real_T c63_b_y;
  real_T c63_g_x;
  real_T c63_c_y;
  real_T c63_h_x;
  real_T c63_d_y;
  real_T c63_e_y;
  real_T c63_i_x;
  real_T c63_j_x;
  real_T c63_c_A;
  real_T c63_k_x;
  real_T c63_l_x;
  real_T c63_m_x;
  real_T c63_d_A;
  real_T c63_n_x;
  real_T c63_o_x;
  real_T c63_p_x;
  real_T c63_e_A;
  real_T c63_q_x;
  real_T c63_r_x;
  real_T c63_s_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c63_sfEvent);
  c63_hoistedGlobal = *chartInstance->c63_f;
  c63_b_hoistedGlobal = *chartInstance->c63_PRGT;
  c63_c_hoistedGlobal = *chartInstance->c63_EFGT;
  c63_d_hoistedGlobal = *chartInstance->c63_T41s;
  c63_e_hoistedGlobal = *chartInstance->c63_Sfcn41;
  c63_b_f = c63_hoistedGlobal;
  c63_b_PRGT = c63_b_hoistedGlobal;
  c63_b_EFGT = c63_c_hoistedGlobal;
  c63_b_T41s = c63_d_hoistedGlobal;
  c63_b_Sfcn41 = c63_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c63_debug_family_names,
    c63_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Sfcn5i, 0U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_T5si, 1U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_DHTi, 2U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_h5cacul, 3U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_a, 4U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b, 5U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_error, 6U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_h5guess, 7U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Z, 8U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargin, 9U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargout, 10U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c63_b_f, 11U, c63_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c63_b_PRGT, 12U, c63_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c63_b_EFGT, 13U, c63_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c63_b_T41s, 14U, c63_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c63_b_Sfcn41, 15U, c63_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_T5s, 16U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_h5, 17U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_Sfcn5, 18U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_DHT_T, 19U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c63_b_PRGT, 1.0, -1, 3U,
        c63_b_PRGT <= 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 3);
    c63_b_PRGT = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 5);
  c63_x = c63_b_PRGT;
  c63_b_x = c63_x;
  if (c63_b_x < 0.0) {
    c63_eml_error(chartInstance);
  }

  c63_realmax(chartInstance);
  c63_b_x = muDoubleScalarLog10(c63_b_x);
  c63_Sfcn5i = c63_b_Sfcn41 - c63_b_x;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 6);
  c63_T5si = c63_Ts_Sfcn_f(chartInstance, c63_Sfcn5i, c63_b_f);
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 7);
  c63_DHTi = c63_gashi(chartInstance, c63_b_T41s, c63_b_f) - c63_gashi
    (chartInstance, c63_T5si, c63_b_f);
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 8);
  c63_b_DHT_T = c63_DHTi * c63_b_EFGT;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 11);
  c63_h5cacul = c63_gashi(chartInstance, c63_b_T41s, c63_b_f) - c63_b_DHT_T;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 12);
  c63_a = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 13);
  c63_b = 5000.0;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 14);
  c63_error = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 15);
  while (CV_EML_WHILE(0, 1, 0, c63_error > 1.0E-9)) {
    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 16);
    c63_A = c63_a + c63_b;
    c63_c_x = c63_A;
    c63_d_x = c63_c_x;
    c63_e_x = c63_d_x;
    c63_y = c63_e_x / 2.0;
    c63_h5guess = c63_gashi(chartInstance, c63_y, c63_b_f);
    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 17);
    c63_b_A = c63_h5cacul - c63_h5guess;
    c63_B = c63_h5cacul;
    c63_f_x = c63_b_A;
    c63_b_y = c63_B;
    c63_g_x = c63_f_x;
    c63_c_y = c63_b_y;
    c63_h_x = c63_g_x;
    c63_d_y = c63_c_y;
    c63_e_y = c63_h_x / c63_d_y;
    c63_i_x = c63_e_y;
    c63_j_x = c63_i_x;
    c63_error = muDoubleScalarAbs(c63_j_x);
    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 18);
    c63_Z = c63_h5guess - c63_h5cacul;
    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 19);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c63_Z, 0.0, -1, 5U,
          c63_Z >= 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 20);
      c63_c_A = c63_a + c63_b;
      c63_k_x = c63_c_A;
      c63_l_x = c63_k_x;
      c63_m_x = c63_l_x;
      c63_b = c63_m_x / 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 22);
      c63_d_A = c63_a + c63_b;
      c63_n_x = c63_d_A;
      c63_o_x = c63_n_x;
      c63_p_x = c63_o_x;
      c63_a = c63_p_x / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 15);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 25);
  c63_e_A = c63_a + c63_b;
  c63_q_x = c63_e_A;
  c63_r_x = c63_q_x;
  c63_s_x = c63_r_x;
  c63_b_T5s = c63_s_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 26);
  c63_b_h5 = c63_gashi(chartInstance, c63_b_T5s, c63_b_f);
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, 27);
  c63_b_Sfcn5 = c63_Sfcn_Ts(chartInstance, c63_b_f, c63_b_T5s);
  _SFD_EML_CALL(0U, chartInstance->c63_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c63_T5s = c63_b_T5s;
  *chartInstance->c63_h5 = c63_b_h5;
  *chartInstance->c63_Sfcn5 = c63_b_Sfcn5;
  *chartInstance->c63_DHT_T = c63_b_DHT_T;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c63_sfEvent);
}

static void initSimStructsc63_TSE_Path(SFc63_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c63_Ts_Sfcn_f(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_Sfcn, real_T c63_b_f)
{
  real_T c63_Ts;
  uint32_T c63_debug_family_var_map[10];
  real_T c63_a;
  real_T c63_b;
  real_T c63_error;
  real_T c63_SfcnGuess;
  real_T c63_Z;
  real_T c63_nargin = 2.0;
  real_T c63_nargout = 1.0;
  real_T c63_A;
  real_T c63_x;
  real_T c63_b_x;
  real_T c63_c_x;
  real_T c63_y;
  real_T c63_b_A;
  real_T c63_B;
  real_T c63_d_x;
  real_T c63_b_y;
  real_T c63_e_x;
  real_T c63_c_y;
  real_T c63_f_x;
  real_T c63_d_y;
  real_T c63_e_y;
  real_T c63_g_x;
  real_T c63_h_x;
  real_T c63_c_A;
  real_T c63_i_x;
  real_T c63_j_x;
  real_T c63_k_x;
  real_T c63_d_A;
  real_T c63_l_x;
  real_T c63_m_x;
  real_T c63_n_x;
  real_T c63_e_A;
  real_T c63_o_x;
  real_T c63_p_x;
  real_T c63_q_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c63_c_debug_family_names,
    c63_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_a, 0U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b, 1U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_error, 2U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_SfcnGuess, 3U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Z, 4U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargin, 5U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargout, 6U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Sfcn, 7U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_f, 8U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Ts, 9U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 2);
  c63_a = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 3);
  c63_b = 3000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 4);
  c63_error = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 5);
  while (CV_SCRIPT_WHILE(0, 0, c63_error >= 1.0E-9)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 6);
    c63_A = c63_a + c63_b;
    c63_x = c63_A;
    c63_b_x = c63_x;
    c63_c_x = c63_b_x;
    c63_y = c63_c_x / 2.0;
    c63_SfcnGuess = c63_Sfcn_Ts(chartInstance, c63_b_f, c63_y);
    _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 7);
    c63_Z = c63_SfcnGuess - c63_Sfcn;
    _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 8);
    c63_b_A = c63_SfcnGuess - c63_Sfcn;
    c63_B = c63_Sfcn;
    c63_d_x = c63_b_A;
    c63_b_y = c63_B;
    c63_e_x = c63_d_x;
    c63_c_y = c63_b_y;
    c63_f_x = c63_e_x;
    c63_d_y = c63_c_y;
    c63_e_y = c63_f_x / c63_d_y;
    c63_g_x = c63_e_y;
    c63_h_x = c63_g_x;
    c63_error = muDoubleScalarAbs(c63_h_x);
    _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 9);
    if (CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c63_Z, 0.0, -1, 4U,
          c63_Z > 0.0))) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 10);
      c63_c_A = c63_a + c63_b;
      c63_i_x = c63_c_A;
      c63_j_x = c63_i_x;
      c63_k_x = c63_j_x;
      c63_b = c63_k_x / 2.0;
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 12);
      c63_d_A = c63_a + c63_b;
      c63_l_x = c63_d_A;
      c63_m_x = c63_l_x;
      c63_n_x = c63_m_x;
      c63_a = c63_n_x / 2.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 5);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, 15);
  c63_e_A = c63_a + c63_b;
  c63_o_x = c63_e_A;
  c63_p_x = c63_o_x;
  c63_q_x = c63_p_x;
  c63_Ts = c63_q_x / 2.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c63_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  return c63_Ts;
}

static real_T c63_Sfcn_Ts(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_b_f, real_T c63_T)
{
  real_T c63_Sfcn;
  uint32_T c63_debug_family_var_map[9];
  real_T c63_T_lib[181];
  real_T c63_psi_lib[181];
  real_T c63_thetapsi_lib[181];
  real_T c63_thetapsi;
  real_T c63_b_T_lib[181];
  real_T c63_nargin = 2.0;
  real_T c63_nargout = 1.0;
  int32_T c63_i0;
  int32_T c63_i1;
  int32_T c63_i2;
  static real_T c63_dv0[181] = { 9.52645662326835, 9.60043021879921,
    9.67095320547355, 9.73833740796616, 9.80285485370918, 9.86474426975119,
    9.92421630463018, 9.98145776420873, 10.0366350767945, 10.089897149933,
    10.1413777426924, 10.1911974488216, 10.239465364947, 10.2862805019933,
    10.3317329858409, 10.3759050838973, 10.4188720870185, 10.4607030705707,
    10.5014615539778, 10.5412060745832, 10.5799906888456, 10.6178654116384,
    10.6548766026051, 10.6910673070487, 10.7264775576255, 10.7611446421339,
    10.7951033418663, 10.8283861443269, 10.8610234335519, 10.8930436608058,
    10.9244734980307, 10.9553379761004, 10.9856606096484, 11.0154635100058,
    11.0447674875824, 11.0735921448526, 11.1019559609634, 11.129876368854,
    11.1573698256671, 11.184451877143, 11.2111372165998, 11.2374397390397,
    11.2633725908557, 11.2889482155604, 11.3141783959148, 11.3390742927899,
    11.3636464810622, 11.3879049828095, 11.4118592980471, 11.4355184332216,
    11.4588909276529, 11.4819848781019, 11.5048079616193, 11.527367456819,
    11.5496702637037, 11.57172292216, 11.5935316292289, 11.6151022552467,
    11.636440358945, 11.6575512015887, 11.6784408828318, 11.6991120966971,
    11.719573653894, 11.7398301334405, 11.7598859539001, 11.7797453809776,
    11.7994125346705, 11.8188913960076, 11.8381858134025, 11.857299508647,
    11.8762360825713, 11.8949990203901, 11.9135916967575, 11.9320173805479,
    11.9502792393817, 11.9683803439115, 11.9863236718835, 12.0041121119888,
    12.0217484675175, 12.0392354598262, 12.0565757316325, 12.0737718501451,
    12.090826310039, 12.1077415362869, 12.1245198868527, 12.1411636552568,
    12.1576750730193, 12.1740563119888, 12.1903094865631, 12.2064366558068,
    12.222439825473, 12.2383209499331, 12.2540819340203, 12.2697246347907,
    12.2852508632075, 12.3006623857508, 12.3159609259588, 12.3311481659018,
    12.346225747594, 12.3611952743459, 12.3760583120594, 12.39081639047,
    12.4054710043373, 12.4200236145874, 12.4344756494082, 12.4488285053018,
    12.4630835480942, 12.4772421139051, 12.4913055100805, 12.5052750160877,
    12.519151884377, 12.5329373412095, 12.5466325874537, 12.5602387993524,
    12.5737571292605, 12.587188706355, 12.6005346373199, 12.6137960070049,
    12.6269738790605, 12.6400692965509, 12.6530832825434, 12.6660168406787,
    12.6788709557191, 12.6916465940792, 12.7043447043369, 12.7169662177274,
    12.7295120486199, 12.741983094978, 12.7543802388048, 12.7667043465727,
    12.7789562696389, 12.7911368446473, 12.803246893917, 12.8152872258177,
    12.8272586351336, 12.8391619034149, 12.8509977993184, 12.8627670789368,
    12.8744704861181, 12.8861087527745, 12.8976825991815, 12.9091927342682,
    12.9206398558985, 12.9320246511427, 12.9433477965427, 12.954609958367,
    12.9658117928596, 12.9769539464805, 12.9880370561396, 12.9990617494234,
    13.0100286448147, 13.0209383519066, 13.0317914716095, 13.0425885963529,
    13.0533303102802, 13.0640171894395, 13.0746498019673, 13.0852287082683,
    13.0957544611898, 13.1062276061903, 13.1166486815051, 13.1270182183055,
    13.1373367408551, 13.1476047666609, 13.1578228066209, 13.1679913651669,
    13.1781109404042, 13.1881820242475, 13.1982051025526, 13.2081806552451,
    13.2181091564456, 13.2279910745918, 13.2378268725567, 13.2476170077649,
    13.2573619323044, 13.2670620930371, 13.2767179317055, 13.2863298850366,
    13.2958983848441, 13.3054238581265, 13.3149067271648 };

  int32_T c63_i3;
  static real_T c63_dv1[181] = { -0.61, -0.57, -0.529362393, -0.487984387,
    -0.44608592, -0.403745859, -0.361038254, -0.31803248, -0.274793367,
    -0.231381349, -0.187852592, -0.144259139, -0.100649045, -0.057066515,
    -0.013552044, 0.029857447, 0.07312847, 0.116230835, 0.159137512, 0.201824488,
    0.244270636, 0.286457571, 0.328369514, 0.369993156, 0.411317516, 0.452333804,
    0.493035286, 0.533417143, 0.573476331, 0.613211449, 0.652622593, 0.691711225,
    0.730480032, 0.768932785, 0.807074206, 0.844909828, 0.882445853, 0.919689021,
    0.956646466, 0.993325582, 1.029733879, 1.065878854, 1.101767843, 1.13740789,
    1.172805607, 1.207967032, 1.242897498, 1.277601489, 1.312082504, 1.346342919,
    1.380383849, 1.414205009, 1.447804576, 1.481179053, 1.514323128, 1.547229537,
    1.579888925, 1.612289711, 1.644417947, 1.676257179, 1.708, 1.74, 1.772,
    1.803, 1.834, 1.866, 1.896, 1.927, 1.958, 1.988, 2.01, 2.049, 2.079, 2.109,
    2.138, 2.168, 2.197, 2.227, 2.256, 2.285, 2.314, 2.342, 2.371, 2.4, 2.428,
    2.456, 2.484, 2.512, 2.54, 2.568, 2.596, 2.624, 2.651, 2.678, 2.706, 2.733,
    2.76, 2.787, 2.814, 2.84, 2.867, 2.894, 2.92, 2.946, 2.973, 2.999, 3.025,
    3.051, 3.077, 3.102, 3.128, 3.154, 3.179, 3.204, 3.23, 3.255, 3.28, 3.305,
    3.33, 3.355, 3.38, 3.404, 3.429, 3.453, 3.478, 3.502, 3.526, 3.55, 3.574,
    3.598, 3.622, 3.646, 3.67, 3.693, 3.717, 3.74, 3.763, 3.787, 3.81, 3.822,
    3.856, 3.879, 3.902, 3.924, 3.947, 3.97, 3.992, 4.015, 4.037, 4.059, 4.081,
    4.103, 4.125, 4.147, 4.169, 4.191, 4.213, 4.234, 4.256, 4.277, 4.299, 4.32,
    4.341, 4.362, 4.383, 4.404, 4.425, 4.446, 4.467, 4.488, 4.508, 4.529, 4.549,
    4.57, 4.59, 4.611, 4.631, 4.651, 4.671, 4.691, 4.711 };

  int32_T c63_i4;
  real_T c63_dv2[181];
  int32_T c63_i5;
  real_T c63_dv3[181];
  real_T c63_A;
  real_T c63_B;
  real_T c63_x;
  real_T c63_y;
  real_T c63_b_x;
  real_T c63_b_y;
  real_T c63_c_x;
  real_T c63_c_y;
  real_T c63_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 10U, c63_b_debug_family_names,
    c63_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c63_T_lib, MAX_uint32_T, c63_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c63_psi_lib, 1U, c63_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c63_thetapsi_lib, 2U, c63_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_thetapsi, 3U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c63_b_T_lib, MAX_uint32_T, c63_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargin, 4U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargout, 5U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_f, 6U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_T, 7U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Sfcn, 8U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 3);
  c63_realmax(chartInstance);
  for (c63_i0 = 0; c63_i0 < 181; c63_i0++) {
    c63_T_lib[c63_i0] = 200.0 + 10.0 * (real_T)c63_i0;
  }

  _SFD_SYMBOL_SWITCH(0U, 0U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 3);
  for (c63_i1 = 0; c63_i1 < 181; c63_i1++) {
    c63_b_T_lib[c63_i1] = 200.0 + 10.0 * (real_T)c63_i1;
  }

  _SFD_SYMBOL_SWITCH(0U, 4U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 4);
  for (c63_i2 = 0; c63_i2 < 181; c63_i2++) {
    c63_psi_lib[c63_i2] = c63_dv0[c63_i2];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 5);
  for (c63_i3 = 0; c63_i3 < 181; c63_i3++) {
    c63_thetapsi_lib[c63_i3] = c63_dv1[c63_i3];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 6);
  c63_Sfcn = c63_interp1(chartInstance, c63_T);
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 7);
  for (c63_i4 = 0; c63_i4 < 181; c63_i4++) {
    c63_dv2[c63_i4] = 200.0 + 10.0 * (real_T)c63_i4;
  }

  for (c63_i5 = 0; c63_i5 < 181; c63_i5++) {
    c63_dv3[c63_i5] = c63_dv1[c63_i5];
  }

  c63_thetapsi = c63_b_interp1(chartInstance, c63_dv2, c63_dv3, c63_T);
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, 8);
  c63_A = c63_b_f;
  c63_B = 1.0 + c63_b_f;
  c63_x = c63_A;
  c63_y = c63_B;
  c63_b_x = c63_x;
  c63_b_y = c63_y;
  c63_c_x = c63_b_x;
  c63_c_y = c63_b_y;
  c63_d_y = c63_c_x / c63_c_y;
  c63_Sfcn += c63_d_y * c63_thetapsi;
  _SFD_SCRIPT_CALL(1U, chartInstance->c63_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  return c63_Sfcn;
}

static real_T c63_gashi(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_T, real_T c63_FuelAirRatio)
{
  real_T c63_Hi;
  uint32_T c63_debug_family_var_map[9];
  real_T c63_b_FuelAirRatio;
  real_T c63_TE;
  real_T c63_Hia;
  real_T c63_Hif;
  real_T c63_nargin = 2.0;
  real_T c63_nargout = 1.0;
  real_T c63_A;
  real_T c63_x;
  real_T c63_b_x;
  real_T c63_c_x;
  real_T c63_b_A;
  real_T c63_d_x;
  real_T c63_e_x;
  real_T c63_f_x;
  real_T c63_c_A;
  real_T c63_B;
  real_T c63_g_x;
  real_T c63_y;
  real_T c63_h_x;
  real_T c63_b_y;
  real_T c63_i_x;
  real_T c63_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c63_d_debug_family_names,
    c63_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_b_FuelAirRatio, 0U,
    c63_sf_marshallOut, c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_TE, 1U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Hia, 2U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Hif, 3U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargin, 4U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_nargout, 5U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_T, 6U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_FuelAirRatio, 7U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c63_Hi, 8U, c63_sf_marshallOut,
    c63_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 6);
  if (CV_SCRIPT_IF(2, 0, CV_RELATIONAL_EVAL(14U, 2U, 0, c63_FuelAirRatio, 0.0,
        -1, 2U, c63_FuelAirRatio < 0.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 7);
    c63_FuelAirRatio = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 10);
  if (CV_SCRIPT_IF(2, 1, CV_RELATIONAL_EVAL(14U, 2U, 1, c63_FuelAirRatio,
        0.067623, -1, 4U, c63_FuelAirRatio > 0.067623))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 11);
    c63_FuelAirRatio = 0.067623;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 14);
  c63_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 16);
  if (CV_SCRIPT_IF(2, 2, CV_RELATIONAL_EVAL(14U, 2U, 2, c63_FuelAirRatio, 0.0,
        -1, 0U, c63_FuelAirRatio == 0.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 17);
    c63_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 21);
  c63_A = c63_T * 9.0;
  c63_x = c63_A;
  c63_b_x = c63_x;
  c63_c_x = c63_b_x;
  c63_TE = c63_c_x / 5.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 22);
  if (CV_SCRIPT_IF(2, 3, CV_RELATIONAL_EVAL(14U, 2U, 3, c63_TE, 300.0, -1, 2U,
        c63_TE < 300.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 23);
    c63_TE = 300.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 26);
  if (CV_SCRIPT_IF(2, 4, CV_RELATIONAL_EVAL(14U, 2U, 4, c63_TE, 4000.0, -1, 4U,
        c63_TE > 4000.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 27);
    c63_TE = 4000.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 31);
  c63_Hia = (((((((1.2644425E-26 * c63_TE - 2.0752522E-22) * c63_TE +
                  1.270263E-18) * c63_TE - 3.0256518E-15) * c63_TE -
                1.6794594E-12) * c63_TE + 2.1839826E-8) * c63_TE - 2.576844E-5) *
             c63_TE + 0.25020051) * c63_TE - 1.7558886;
  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 33);
  switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c63_b_FuelAirRatio)) {
   case 1:
    CV_SCRIPT_SWITCH(2, 0, 1);
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 38);
    c63_Hi = c63_Hia * 2.3254259;
    break;

   default:
    CV_SCRIPT_SWITCH(2, 0, 0);
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 42);
    c63_Hif = (((((((9.0848388E-26 * c63_TE - 1.9050949E-21) * c63_TE +
                    1.7021525E-17) * c63_TE - 8.4102208E-14) * c63_TE +
                  2.4921698E-10) * c63_TE - 4.5906332E-7) * c63_TE +
                0.0006129315) * c63_TE + 0.073816638) * c63_TE + 30.58153;
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 43);
    c63_c_A = c63_Hia + c63_FuelAirRatio * c63_Hif;
    c63_B = 1.0 + c63_FuelAirRatio;
    c63_g_x = c63_c_A;
    c63_y = c63_B;
    c63_h_x = c63_g_x;
    c63_b_y = c63_y;
    c63_i_x = c63_h_x;
    c63_c_y = c63_b_y;
    c63_Hif = c63_i_x / c63_c_y;
    _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 46);
    c63_Hi = c63_Hif * 2.3254259;
    break;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, 48);
  c63_b_A = c63_TE * 5.0;
  c63_d_x = c63_b_A;
  c63_e_x = c63_d_x;
  c63_f_x = c63_e_x;
  c63_T = c63_f_x / 9.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c63_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  return c63_Hi;
}

static void init_script_number_translation(uint32_T c63_machineNumber, uint32_T
  c63_chartNumber, uint32_T c63_instanceNumber)
{
  (void)c63_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c63_chartNumber, c63_instanceNumber, 0U,
    sf_debug_get_script_id(
    "I:\\MATLABWORK\\TSE4.0\\FunctionsLibrary\\Ts_Sfcn_f.m"));
  _SFD_SCRIPT_TRANSLATION(c63_chartNumber, c63_instanceNumber, 1U,
    sf_debug_get_script_id(
    "I:\\MATLABWORK\\GTFEngine\\FunctionsLibrary\\Sfcn_Ts.m"));
  _SFD_SCRIPT_TRANSLATION(c63_chartNumber, c63_instanceNumber, 2U,
    sf_debug_get_script_id(
    "I:\\MATLABWORK\\GTFEngine\\FunctionsLibrary\\gashi.m"));
}

static const mxArray *c63_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData)
{
  const mxArray *c63_mxArrayOutData = NULL;
  real_T c63_u;
  const mxArray *c63_y = NULL;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_mxArrayOutData = NULL;
  c63_u = *(real_T *)c63_inData;
  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", &c63_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c63_mxArrayOutData, c63_y, false);
  return c63_mxArrayOutData;
}

static real_T c63_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c63_b_DHT_T, const char_T *c63_identifier)
{
  real_T c63_y;
  emlrtMsgIdentifier c63_thisId;
  c63_thisId.fIdentifier = c63_identifier;
  c63_thisId.fParent = NULL;
  c63_y = c63_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c63_b_DHT_T),
    &c63_thisId);
  sf_mex_destroy(&c63_b_DHT_T);
  return c63_y;
}

static real_T c63_b_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId)
{
  real_T c63_y;
  real_T c63_d0;
  (void)chartInstance;
  sf_mex_import(c63_parentId, sf_mex_dup(c63_u), &c63_d0, 1, 0, 0U, 0, 0U, 0);
  c63_y = c63_d0;
  sf_mex_destroy(&c63_u);
  return c63_y;
}

static void c63_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c63_mxArrayInData, const char_T *c63_varName, void *c63_outData)
{
  const mxArray *c63_b_DHT_T;
  const char_T *c63_identifier;
  emlrtMsgIdentifier c63_thisId;
  real_T c63_y;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_b_DHT_T = sf_mex_dup(c63_mxArrayInData);
  c63_identifier = c63_varName;
  c63_thisId.fIdentifier = c63_identifier;
  c63_thisId.fParent = NULL;
  c63_y = c63_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c63_b_DHT_T),
    &c63_thisId);
  sf_mex_destroy(&c63_b_DHT_T);
  *(real_T *)c63_outData = c63_y;
  sf_mex_destroy(&c63_mxArrayInData);
}

static const mxArray *c63_b_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData)
{
  const mxArray *c63_mxArrayOutData = NULL;
  int32_T c63_i6;
  real_T c63_b_inData[181];
  int32_T c63_i7;
  real_T c63_u[181];
  const mxArray *c63_y = NULL;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_mxArrayOutData = NULL;
  for (c63_i6 = 0; c63_i6 < 181; c63_i6++) {
    c63_b_inData[c63_i6] = (*(real_T (*)[181])c63_inData)[c63_i6];
  }

  for (c63_i7 = 0; c63_i7 < 181; c63_i7++) {
    c63_u[c63_i7] = c63_b_inData[c63_i7];
  }

  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 0, 0U, 1U, 0U, 1, 181), false);
  sf_mex_assign(&c63_mxArrayOutData, c63_y, false);
  return c63_mxArrayOutData;
}

static const mxArray *c63_c_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData)
{
  const mxArray *c63_mxArrayOutData = NULL;
  int32_T c63_i8;
  real_T c63_b_inData[181];
  int32_T c63_i9;
  real_T c63_u[181];
  const mxArray *c63_y = NULL;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_mxArrayOutData = NULL;
  for (c63_i8 = 0; c63_i8 < 181; c63_i8++) {
    c63_b_inData[c63_i8] = (*(real_T (*)[181])c63_inData)[c63_i8];
  }

  for (c63_i9 = 0; c63_i9 < 181; c63_i9++) {
    c63_u[c63_i9] = c63_b_inData[c63_i9];
  }

  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 0, 0U, 1U, 0U, 2, 1, 181),
                false);
  sf_mex_assign(&c63_mxArrayOutData, c63_y, false);
  return c63_mxArrayOutData;
}

const mxArray *sf_c63_TSE_Path_get_eml_resolved_functions_info(void)
{
  const mxArray *c63_nameCaptureInfo = NULL;
  c63_nameCaptureInfo = NULL;
  sf_mex_assign(&c63_nameCaptureInfo, sf_mex_createstruct("structure", 2, 119, 1),
                false);
  c63_info_helper(&c63_nameCaptureInfo);
  c63_b_info_helper(&c63_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c63_nameCaptureInfo);
  return c63_nameCaptureInfo;
}

static void c63_info_helper(const mxArray **c63_info)
{
  const mxArray *c63_rhs0 = NULL;
  const mxArray *c63_lhs0 = NULL;
  const mxArray *c63_rhs1 = NULL;
  const mxArray *c63_lhs1 = NULL;
  const mxArray *c63_rhs2 = NULL;
  const mxArray *c63_lhs2 = NULL;
  const mxArray *c63_rhs3 = NULL;
  const mxArray *c63_lhs3 = NULL;
  const mxArray *c63_rhs4 = NULL;
  const mxArray *c63_lhs4 = NULL;
  const mxArray *c63_rhs5 = NULL;
  const mxArray *c63_lhs5 = NULL;
  const mxArray *c63_rhs6 = NULL;
  const mxArray *c63_lhs6 = NULL;
  const mxArray *c63_rhs7 = NULL;
  const mxArray *c63_lhs7 = NULL;
  const mxArray *c63_rhs8 = NULL;
  const mxArray *c63_lhs8 = NULL;
  const mxArray *c63_rhs9 = NULL;
  const mxArray *c63_lhs9 = NULL;
  const mxArray *c63_rhs10 = NULL;
  const mxArray *c63_lhs10 = NULL;
  const mxArray *c63_rhs11 = NULL;
  const mxArray *c63_lhs11 = NULL;
  const mxArray *c63_rhs12 = NULL;
  const mxArray *c63_lhs12 = NULL;
  const mxArray *c63_rhs13 = NULL;
  const mxArray *c63_lhs13 = NULL;
  const mxArray *c63_rhs14 = NULL;
  const mxArray *c63_lhs14 = NULL;
  const mxArray *c63_rhs15 = NULL;
  const mxArray *c63_lhs15 = NULL;
  const mxArray *c63_rhs16 = NULL;
  const mxArray *c63_lhs16 = NULL;
  const mxArray *c63_rhs17 = NULL;
  const mxArray *c63_lhs17 = NULL;
  const mxArray *c63_rhs18 = NULL;
  const mxArray *c63_lhs18 = NULL;
  const mxArray *c63_rhs19 = NULL;
  const mxArray *c63_lhs19 = NULL;
  const mxArray *c63_rhs20 = NULL;
  const mxArray *c63_lhs20 = NULL;
  const mxArray *c63_rhs21 = NULL;
  const mxArray *c63_lhs21 = NULL;
  const mxArray *c63_rhs22 = NULL;
  const mxArray *c63_lhs22 = NULL;
  const mxArray *c63_rhs23 = NULL;
  const mxArray *c63_lhs23 = NULL;
  const mxArray *c63_rhs24 = NULL;
  const mxArray *c63_lhs24 = NULL;
  const mxArray *c63_rhs25 = NULL;
  const mxArray *c63_lhs25 = NULL;
  const mxArray *c63_rhs26 = NULL;
  const mxArray *c63_lhs26 = NULL;
  const mxArray *c63_rhs27 = NULL;
  const mxArray *c63_lhs27 = NULL;
  const mxArray *c63_rhs28 = NULL;
  const mxArray *c63_lhs28 = NULL;
  const mxArray *c63_rhs29 = NULL;
  const mxArray *c63_lhs29 = NULL;
  const mxArray *c63_rhs30 = NULL;
  const mxArray *c63_lhs30 = NULL;
  const mxArray *c63_rhs31 = NULL;
  const mxArray *c63_lhs31 = NULL;
  const mxArray *c63_rhs32 = NULL;
  const mxArray *c63_lhs32 = NULL;
  const mxArray *c63_rhs33 = NULL;
  const mxArray *c63_lhs33 = NULL;
  const mxArray *c63_rhs34 = NULL;
  const mxArray *c63_lhs34 = NULL;
  const mxArray *c63_rhs35 = NULL;
  const mxArray *c63_lhs35 = NULL;
  const mxArray *c63_rhs36 = NULL;
  const mxArray *c63_lhs36 = NULL;
  const mxArray *c63_rhs37 = NULL;
  const mxArray *c63_lhs37 = NULL;
  const mxArray *c63_rhs38 = NULL;
  const mxArray *c63_lhs38 = NULL;
  const mxArray *c63_rhs39 = NULL;
  const mxArray *c63_lhs39 = NULL;
  const mxArray *c63_rhs40 = NULL;
  const mxArray *c63_lhs40 = NULL;
  const mxArray *c63_rhs41 = NULL;
  const mxArray *c63_lhs41 = NULL;
  const mxArray *c63_rhs42 = NULL;
  const mxArray *c63_lhs42 = NULL;
  const mxArray *c63_rhs43 = NULL;
  const mxArray *c63_lhs43 = NULL;
  const mxArray *c63_rhs44 = NULL;
  const mxArray *c63_lhs44 = NULL;
  const mxArray *c63_rhs45 = NULL;
  const mxArray *c63_lhs45 = NULL;
  const mxArray *c63_rhs46 = NULL;
  const mxArray *c63_lhs46 = NULL;
  const mxArray *c63_rhs47 = NULL;
  const mxArray *c63_lhs47 = NULL;
  const mxArray *c63_rhs48 = NULL;
  const mxArray *c63_lhs48 = NULL;
  const mxArray *c63_rhs49 = NULL;
  const mxArray *c63_lhs49 = NULL;
  const mxArray *c63_rhs50 = NULL;
  const mxArray *c63_lhs50 = NULL;
  const mxArray *c63_rhs51 = NULL;
  const mxArray *c63_lhs51 = NULL;
  const mxArray *c63_rhs52 = NULL;
  const mxArray *c63_lhs52 = NULL;
  const mxArray *c63_rhs53 = NULL;
  const mxArray *c63_lhs53 = NULL;
  const mxArray *c63_rhs54 = NULL;
  const mxArray *c63_lhs54 = NULL;
  const mxArray *c63_rhs55 = NULL;
  const mxArray *c63_lhs55 = NULL;
  const mxArray *c63_rhs56 = NULL;
  const mxArray *c63_lhs56 = NULL;
  const mxArray *c63_rhs57 = NULL;
  const mxArray *c63_lhs57 = NULL;
  const mxArray *c63_rhs58 = NULL;
  const mxArray *c63_lhs58 = NULL;
  const mxArray *c63_rhs59 = NULL;
  const mxArray *c63_lhs59 = NULL;
  const mxArray *c63_rhs60 = NULL;
  const mxArray *c63_lhs60 = NULL;
  const mxArray *c63_rhs61 = NULL;
  const mxArray *c63_lhs61 = NULL;
  const mxArray *c63_rhs62 = NULL;
  const mxArray *c63_lhs62 = NULL;
  const mxArray *c63_rhs63 = NULL;
  const mxArray *c63_lhs63 = NULL;
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("log10"), "name", "name", 0);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395303300U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c63_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_error"), "name", "name",
                  1);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c63_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 2);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1286797128U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c63_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("realmax"), "name", "name", 3);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1307629642U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c63_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 4);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c63_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 5);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c63_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  6);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c63_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 7);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c63_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 8);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("rdivide"), "name", "name", 8);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c63_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c63_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 10);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c63_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_div"), "name", "name",
                  11);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c63_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 12);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c63_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("Ts_Sfcn_f"), "name", "name",
                  13);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/TSE4.0/FunctionsLibrary/Ts_Sfcn_f.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1462176276U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c63_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/TSE4.0/FunctionsLibrary/Ts_Sfcn_f.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  14);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c63_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/TSE4.0/FunctionsLibrary/Ts_Sfcn_f.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("Sfcn_Ts"), "name", "name",
                  15);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/Sfcn_Ts.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1447835225U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c63_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/Sfcn_Ts.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("colon"), "name", "name", 16);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1378274388U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c63_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c63_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 18);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isfinite"), "name", "name",
                  18);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688656U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c63_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c63_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isinf"), "name", "name", 20);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688656U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c63_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c63_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c63_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c63_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 24);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("floor"), "name", "name", 24);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c63_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c63_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 26);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c63_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 27);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c63_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 28);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c63_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 29);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("flintmax"), "name", "name",
                  29);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1348170316U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c63_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 30);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c63_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 31);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("abs"), "name", "name", 31);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c63_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c63_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 33);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c63_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 34);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("realmax"), "name", "name",
                  34);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1307629642U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c63_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 35);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  35);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c63_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 36);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("floor"), "name", "name", 36);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c63_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 37);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 37);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c63_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 38);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 38);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c63_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1393305658U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c63_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/Sfcn_Ts.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("interp1"), "name", "name",
                  40);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1381828706U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c63_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 41);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c63_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 42);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 42);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c63_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 43);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 43);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c63_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 44);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 44);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c63_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 45);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("length"), "name", "name", 45);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1303124606U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c63_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 46);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("max"), "name", "name", 46);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1311233716U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c63_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 47);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1378274384U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c63_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 48);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 48);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c63_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 49);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 49);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c63_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 50);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c63_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 51);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c63_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 52);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 52);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c63_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 53);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c63_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 54);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("strncmpi"), "name", "name",
                  54);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1328832722U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c63_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 55);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c63_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 56);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 56);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c63_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 57);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c63_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("min"), "name", "name", 58);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1311233718U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c63_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1378274384U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c63_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("lower"), "name", "name", 60);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c63_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 61);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c63_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 62);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c63_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 63);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c63_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c63_rhs0);
  sf_mex_destroy(&c63_lhs0);
  sf_mex_destroy(&c63_rhs1);
  sf_mex_destroy(&c63_lhs1);
  sf_mex_destroy(&c63_rhs2);
  sf_mex_destroy(&c63_lhs2);
  sf_mex_destroy(&c63_rhs3);
  sf_mex_destroy(&c63_lhs3);
  sf_mex_destroy(&c63_rhs4);
  sf_mex_destroy(&c63_lhs4);
  sf_mex_destroy(&c63_rhs5);
  sf_mex_destroy(&c63_lhs5);
  sf_mex_destroy(&c63_rhs6);
  sf_mex_destroy(&c63_lhs6);
  sf_mex_destroy(&c63_rhs7);
  sf_mex_destroy(&c63_lhs7);
  sf_mex_destroy(&c63_rhs8);
  sf_mex_destroy(&c63_lhs8);
  sf_mex_destroy(&c63_rhs9);
  sf_mex_destroy(&c63_lhs9);
  sf_mex_destroy(&c63_rhs10);
  sf_mex_destroy(&c63_lhs10);
  sf_mex_destroy(&c63_rhs11);
  sf_mex_destroy(&c63_lhs11);
  sf_mex_destroy(&c63_rhs12);
  sf_mex_destroy(&c63_lhs12);
  sf_mex_destroy(&c63_rhs13);
  sf_mex_destroy(&c63_lhs13);
  sf_mex_destroy(&c63_rhs14);
  sf_mex_destroy(&c63_lhs14);
  sf_mex_destroy(&c63_rhs15);
  sf_mex_destroy(&c63_lhs15);
  sf_mex_destroy(&c63_rhs16);
  sf_mex_destroy(&c63_lhs16);
  sf_mex_destroy(&c63_rhs17);
  sf_mex_destroy(&c63_lhs17);
  sf_mex_destroy(&c63_rhs18);
  sf_mex_destroy(&c63_lhs18);
  sf_mex_destroy(&c63_rhs19);
  sf_mex_destroy(&c63_lhs19);
  sf_mex_destroy(&c63_rhs20);
  sf_mex_destroy(&c63_lhs20);
  sf_mex_destroy(&c63_rhs21);
  sf_mex_destroy(&c63_lhs21);
  sf_mex_destroy(&c63_rhs22);
  sf_mex_destroy(&c63_lhs22);
  sf_mex_destroy(&c63_rhs23);
  sf_mex_destroy(&c63_lhs23);
  sf_mex_destroy(&c63_rhs24);
  sf_mex_destroy(&c63_lhs24);
  sf_mex_destroy(&c63_rhs25);
  sf_mex_destroy(&c63_lhs25);
  sf_mex_destroy(&c63_rhs26);
  sf_mex_destroy(&c63_lhs26);
  sf_mex_destroy(&c63_rhs27);
  sf_mex_destroy(&c63_lhs27);
  sf_mex_destroy(&c63_rhs28);
  sf_mex_destroy(&c63_lhs28);
  sf_mex_destroy(&c63_rhs29);
  sf_mex_destroy(&c63_lhs29);
  sf_mex_destroy(&c63_rhs30);
  sf_mex_destroy(&c63_lhs30);
  sf_mex_destroy(&c63_rhs31);
  sf_mex_destroy(&c63_lhs31);
  sf_mex_destroy(&c63_rhs32);
  sf_mex_destroy(&c63_lhs32);
  sf_mex_destroy(&c63_rhs33);
  sf_mex_destroy(&c63_lhs33);
  sf_mex_destroy(&c63_rhs34);
  sf_mex_destroy(&c63_lhs34);
  sf_mex_destroy(&c63_rhs35);
  sf_mex_destroy(&c63_lhs35);
  sf_mex_destroy(&c63_rhs36);
  sf_mex_destroy(&c63_lhs36);
  sf_mex_destroy(&c63_rhs37);
  sf_mex_destroy(&c63_lhs37);
  sf_mex_destroy(&c63_rhs38);
  sf_mex_destroy(&c63_lhs38);
  sf_mex_destroy(&c63_rhs39);
  sf_mex_destroy(&c63_lhs39);
  sf_mex_destroy(&c63_rhs40);
  sf_mex_destroy(&c63_lhs40);
  sf_mex_destroy(&c63_rhs41);
  sf_mex_destroy(&c63_lhs41);
  sf_mex_destroy(&c63_rhs42);
  sf_mex_destroy(&c63_lhs42);
  sf_mex_destroy(&c63_rhs43);
  sf_mex_destroy(&c63_lhs43);
  sf_mex_destroy(&c63_rhs44);
  sf_mex_destroy(&c63_lhs44);
  sf_mex_destroy(&c63_rhs45);
  sf_mex_destroy(&c63_lhs45);
  sf_mex_destroy(&c63_rhs46);
  sf_mex_destroy(&c63_lhs46);
  sf_mex_destroy(&c63_rhs47);
  sf_mex_destroy(&c63_lhs47);
  sf_mex_destroy(&c63_rhs48);
  sf_mex_destroy(&c63_lhs48);
  sf_mex_destroy(&c63_rhs49);
  sf_mex_destroy(&c63_lhs49);
  sf_mex_destroy(&c63_rhs50);
  sf_mex_destroy(&c63_lhs50);
  sf_mex_destroy(&c63_rhs51);
  sf_mex_destroy(&c63_lhs51);
  sf_mex_destroy(&c63_rhs52);
  sf_mex_destroy(&c63_lhs52);
  sf_mex_destroy(&c63_rhs53);
  sf_mex_destroy(&c63_lhs53);
  sf_mex_destroy(&c63_rhs54);
  sf_mex_destroy(&c63_lhs54);
  sf_mex_destroy(&c63_rhs55);
  sf_mex_destroy(&c63_lhs55);
  sf_mex_destroy(&c63_rhs56);
  sf_mex_destroy(&c63_lhs56);
  sf_mex_destroy(&c63_rhs57);
  sf_mex_destroy(&c63_lhs57);
  sf_mex_destroy(&c63_rhs58);
  sf_mex_destroy(&c63_lhs58);
  sf_mex_destroy(&c63_rhs59);
  sf_mex_destroy(&c63_lhs59);
  sf_mex_destroy(&c63_rhs60);
  sf_mex_destroy(&c63_lhs60);
  sf_mex_destroy(&c63_rhs61);
  sf_mex_destroy(&c63_lhs61);
  sf_mex_destroy(&c63_rhs62);
  sf_mex_destroy(&c63_lhs62);
  sf_mex_destroy(&c63_rhs63);
  sf_mex_destroy(&c63_lhs63);
}

static const mxArray *c63_emlrt_marshallOut(const char * c63_u)
{
  const mxArray *c63_y = NULL;
  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c63_u)), false);
  return c63_y;
}

static const mxArray *c63_b_emlrt_marshallOut(const uint32_T c63_u)
{
  const mxArray *c63_y = NULL;
  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", &c63_u, 7, 0U, 0U, 0U, 0), false);
  return c63_y;
}

static void c63_b_info_helper(const mxArray **c63_info)
{
  const mxArray *c63_rhs64 = NULL;
  const mxArray *c63_lhs64 = NULL;
  const mxArray *c63_rhs65 = NULL;
  const mxArray *c63_lhs65 = NULL;
  const mxArray *c63_rhs66 = NULL;
  const mxArray *c63_lhs66 = NULL;
  const mxArray *c63_rhs67 = NULL;
  const mxArray *c63_lhs67 = NULL;
  const mxArray *c63_rhs68 = NULL;
  const mxArray *c63_lhs68 = NULL;
  const mxArray *c63_rhs69 = NULL;
  const mxArray *c63_lhs69 = NULL;
  const mxArray *c63_rhs70 = NULL;
  const mxArray *c63_lhs70 = NULL;
  const mxArray *c63_rhs71 = NULL;
  const mxArray *c63_lhs71 = NULL;
  const mxArray *c63_rhs72 = NULL;
  const mxArray *c63_lhs72 = NULL;
  const mxArray *c63_rhs73 = NULL;
  const mxArray *c63_lhs73 = NULL;
  const mxArray *c63_rhs74 = NULL;
  const mxArray *c63_lhs74 = NULL;
  const mxArray *c63_rhs75 = NULL;
  const mxArray *c63_lhs75 = NULL;
  const mxArray *c63_rhs76 = NULL;
  const mxArray *c63_lhs76 = NULL;
  const mxArray *c63_rhs77 = NULL;
  const mxArray *c63_lhs77 = NULL;
  const mxArray *c63_rhs78 = NULL;
  const mxArray *c63_lhs78 = NULL;
  const mxArray *c63_rhs79 = NULL;
  const mxArray *c63_lhs79 = NULL;
  const mxArray *c63_rhs80 = NULL;
  const mxArray *c63_lhs80 = NULL;
  const mxArray *c63_rhs81 = NULL;
  const mxArray *c63_lhs81 = NULL;
  const mxArray *c63_rhs82 = NULL;
  const mxArray *c63_lhs82 = NULL;
  const mxArray *c63_rhs83 = NULL;
  const mxArray *c63_lhs83 = NULL;
  const mxArray *c63_rhs84 = NULL;
  const mxArray *c63_lhs84 = NULL;
  const mxArray *c63_rhs85 = NULL;
  const mxArray *c63_lhs85 = NULL;
  const mxArray *c63_rhs86 = NULL;
  const mxArray *c63_lhs86 = NULL;
  const mxArray *c63_rhs87 = NULL;
  const mxArray *c63_lhs87 = NULL;
  const mxArray *c63_rhs88 = NULL;
  const mxArray *c63_lhs88 = NULL;
  const mxArray *c63_rhs89 = NULL;
  const mxArray *c63_lhs89 = NULL;
  const mxArray *c63_rhs90 = NULL;
  const mxArray *c63_lhs90 = NULL;
  const mxArray *c63_rhs91 = NULL;
  const mxArray *c63_lhs91 = NULL;
  const mxArray *c63_rhs92 = NULL;
  const mxArray *c63_lhs92 = NULL;
  const mxArray *c63_rhs93 = NULL;
  const mxArray *c63_lhs93 = NULL;
  const mxArray *c63_rhs94 = NULL;
  const mxArray *c63_lhs94 = NULL;
  const mxArray *c63_rhs95 = NULL;
  const mxArray *c63_lhs95 = NULL;
  const mxArray *c63_rhs96 = NULL;
  const mxArray *c63_lhs96 = NULL;
  const mxArray *c63_rhs97 = NULL;
  const mxArray *c63_lhs97 = NULL;
  const mxArray *c63_rhs98 = NULL;
  const mxArray *c63_lhs98 = NULL;
  const mxArray *c63_rhs99 = NULL;
  const mxArray *c63_lhs99 = NULL;
  const mxArray *c63_rhs100 = NULL;
  const mxArray *c63_lhs100 = NULL;
  const mxArray *c63_rhs101 = NULL;
  const mxArray *c63_lhs101 = NULL;
  const mxArray *c63_rhs102 = NULL;
  const mxArray *c63_lhs102 = NULL;
  const mxArray *c63_rhs103 = NULL;
  const mxArray *c63_lhs103 = NULL;
  const mxArray *c63_rhs104 = NULL;
  const mxArray *c63_lhs104 = NULL;
  const mxArray *c63_rhs105 = NULL;
  const mxArray *c63_lhs105 = NULL;
  const mxArray *c63_rhs106 = NULL;
  const mxArray *c63_lhs106 = NULL;
  const mxArray *c63_rhs107 = NULL;
  const mxArray *c63_lhs107 = NULL;
  const mxArray *c63_rhs108 = NULL;
  const mxArray *c63_lhs108 = NULL;
  const mxArray *c63_rhs109 = NULL;
  const mxArray *c63_lhs109 = NULL;
  const mxArray *c63_rhs110 = NULL;
  const mxArray *c63_lhs110 = NULL;
  const mxArray *c63_rhs111 = NULL;
  const mxArray *c63_lhs111 = NULL;
  const mxArray *c63_rhs112 = NULL;
  const mxArray *c63_lhs112 = NULL;
  const mxArray *c63_rhs113 = NULL;
  const mxArray *c63_lhs113 = NULL;
  const mxArray *c63_rhs114 = NULL;
  const mxArray *c63_lhs114 = NULL;
  const mxArray *c63_rhs115 = NULL;
  const mxArray *c63_lhs115 = NULL;
  const mxArray *c63_rhs116 = NULL;
  const mxArray *c63_lhs116 = NULL;
  const mxArray *c63_rhs117 = NULL;
  const mxArray *c63_lhs117 = NULL;
  const mxArray *c63_rhs118 = NULL;
  const mxArray *c63_lhs118 = NULL;
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 64);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1327393910U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c63_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("colon"), "name", "name", 65);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1378274388U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c63_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("colon"), "name", "name", 66);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1378274388U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c63_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 67);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c63_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("floor"), "name", "name", 68);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c63_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 69);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmin"), "name", "name", 69);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c63_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 70);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1393305658U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c63_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 71);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 71);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c63_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 72);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmin"), "name", "name", 72);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c63_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 73);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 73);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c63_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 74);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 74);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c63_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 75);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c63_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 76);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 76);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c63_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 77);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c63_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 78);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1393305658U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c63_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 79);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 79);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c63_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 80);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 80);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c63_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 81);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 81);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c63_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 82);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 82);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1372560816U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c63_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 83);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1372561560U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c63_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 84);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 84);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1397235822U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c63_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 85);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isfi"), "name", "name", 85);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 85);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1346488758U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c63_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 86);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 86);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1398853998U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c63_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 87);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name", 87);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c63_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 88);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmin"), "name", "name", 88);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c63_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 89);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "name", "name", 89);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 89);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1319708368U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c63_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 90);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.nan"), "name",
                  "name", 90);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/nan.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236832U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c63_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 91);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.prodsize"),
                  "name", "name", 91);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1360257388U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c63_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 92);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 92);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1397235822U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c63_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 93);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isnan"), "name", "name", 93);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 93);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688658U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c63_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 94);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_error"), "name", "name",
                  94);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c63_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 95);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("isnan"), "name", "name", 95);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688658U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c63_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 96);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.nan"), "name",
                  "name", 96);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/nan.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236832U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c63_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 97);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.bsearch"),
                  "name", "name", 97);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c63_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.narginchk"),
                  "name", "name", 98);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363689358U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c63_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 99);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("floor"), "name", "name", 99);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c63_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 100);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 100);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c63_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "context", "context", 101);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name",
                  101);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c63_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 102);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  102);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 102);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c63_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 103);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("flip"), "name", "name", 103);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flip.m"), "resolved",
                  "resolved", 103);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1372560814U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c63_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flip.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 104);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c63_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flip.m"), "context",
                  "context", 105);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("eml_assert_valid_dim"),
                  "name", "name", 105);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1372560816U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c63_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "context", "context", 106);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.assertValidDim"), "name", "name", 106);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1372561560U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c63_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 107);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 107);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c63_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 108);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("floor"), "name", "name", 108);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c63_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 109);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("intmax"), "name", "name",
                  109);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c63_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flip.m"), "context",
                  "context", 110);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("coder.internal.prodsize"),
                  "name", "name", 110);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1360257388U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c63_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flip.m"), "context",
                  "context", 111);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 111);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1397235822U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c63_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/Sfcn_Ts.m"), "context",
                  "context", 112);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  112);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c63_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/TSE4.0/FunctionsLibrary/Ts_Sfcn_f.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("abs"), "name", "name", 113);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 113);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c63_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context",
                  114);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("gashi"), "name", "name", 114);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "resolved",
                  "resolved", 114);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1428734872U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c63_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "context", "context",
                  115);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  115);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 115);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c63_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context",
                  116);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("mrdivide"), "name", "name",
                  116);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c63_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context",
                  117);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("abs"), "name", "name", 117);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 117);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c63_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(""), "context", "context",
                  118);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("Sfcn_Ts"), "name", "name",
                  118);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c63_info, c63_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/Sfcn_Ts.m"), "resolved",
                  "resolved", 118);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(1447835225U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c63_info, c63_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c63_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c63_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c63_info, sf_mex_duplicatearraysafe(&c63_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_destroy(&c63_rhs64);
  sf_mex_destroy(&c63_lhs64);
  sf_mex_destroy(&c63_rhs65);
  sf_mex_destroy(&c63_lhs65);
  sf_mex_destroy(&c63_rhs66);
  sf_mex_destroy(&c63_lhs66);
  sf_mex_destroy(&c63_rhs67);
  sf_mex_destroy(&c63_lhs67);
  sf_mex_destroy(&c63_rhs68);
  sf_mex_destroy(&c63_lhs68);
  sf_mex_destroy(&c63_rhs69);
  sf_mex_destroy(&c63_lhs69);
  sf_mex_destroy(&c63_rhs70);
  sf_mex_destroy(&c63_lhs70);
  sf_mex_destroy(&c63_rhs71);
  sf_mex_destroy(&c63_lhs71);
  sf_mex_destroy(&c63_rhs72);
  sf_mex_destroy(&c63_lhs72);
  sf_mex_destroy(&c63_rhs73);
  sf_mex_destroy(&c63_lhs73);
  sf_mex_destroy(&c63_rhs74);
  sf_mex_destroy(&c63_lhs74);
  sf_mex_destroy(&c63_rhs75);
  sf_mex_destroy(&c63_lhs75);
  sf_mex_destroy(&c63_rhs76);
  sf_mex_destroy(&c63_lhs76);
  sf_mex_destroy(&c63_rhs77);
  sf_mex_destroy(&c63_lhs77);
  sf_mex_destroy(&c63_rhs78);
  sf_mex_destroy(&c63_lhs78);
  sf_mex_destroy(&c63_rhs79);
  sf_mex_destroy(&c63_lhs79);
  sf_mex_destroy(&c63_rhs80);
  sf_mex_destroy(&c63_lhs80);
  sf_mex_destroy(&c63_rhs81);
  sf_mex_destroy(&c63_lhs81);
  sf_mex_destroy(&c63_rhs82);
  sf_mex_destroy(&c63_lhs82);
  sf_mex_destroy(&c63_rhs83);
  sf_mex_destroy(&c63_lhs83);
  sf_mex_destroy(&c63_rhs84);
  sf_mex_destroy(&c63_lhs84);
  sf_mex_destroy(&c63_rhs85);
  sf_mex_destroy(&c63_lhs85);
  sf_mex_destroy(&c63_rhs86);
  sf_mex_destroy(&c63_lhs86);
  sf_mex_destroy(&c63_rhs87);
  sf_mex_destroy(&c63_lhs87);
  sf_mex_destroy(&c63_rhs88);
  sf_mex_destroy(&c63_lhs88);
  sf_mex_destroy(&c63_rhs89);
  sf_mex_destroy(&c63_lhs89);
  sf_mex_destroy(&c63_rhs90);
  sf_mex_destroy(&c63_lhs90);
  sf_mex_destroy(&c63_rhs91);
  sf_mex_destroy(&c63_lhs91);
  sf_mex_destroy(&c63_rhs92);
  sf_mex_destroy(&c63_lhs92);
  sf_mex_destroy(&c63_rhs93);
  sf_mex_destroy(&c63_lhs93);
  sf_mex_destroy(&c63_rhs94);
  sf_mex_destroy(&c63_lhs94);
  sf_mex_destroy(&c63_rhs95);
  sf_mex_destroy(&c63_lhs95);
  sf_mex_destroy(&c63_rhs96);
  sf_mex_destroy(&c63_lhs96);
  sf_mex_destroy(&c63_rhs97);
  sf_mex_destroy(&c63_lhs97);
  sf_mex_destroy(&c63_rhs98);
  sf_mex_destroy(&c63_lhs98);
  sf_mex_destroy(&c63_rhs99);
  sf_mex_destroy(&c63_lhs99);
  sf_mex_destroy(&c63_rhs100);
  sf_mex_destroy(&c63_lhs100);
  sf_mex_destroy(&c63_rhs101);
  sf_mex_destroy(&c63_lhs101);
  sf_mex_destroy(&c63_rhs102);
  sf_mex_destroy(&c63_lhs102);
  sf_mex_destroy(&c63_rhs103);
  sf_mex_destroy(&c63_lhs103);
  sf_mex_destroy(&c63_rhs104);
  sf_mex_destroy(&c63_lhs104);
  sf_mex_destroy(&c63_rhs105);
  sf_mex_destroy(&c63_lhs105);
  sf_mex_destroy(&c63_rhs106);
  sf_mex_destroy(&c63_lhs106);
  sf_mex_destroy(&c63_rhs107);
  sf_mex_destroy(&c63_lhs107);
  sf_mex_destroy(&c63_rhs108);
  sf_mex_destroy(&c63_lhs108);
  sf_mex_destroy(&c63_rhs109);
  sf_mex_destroy(&c63_lhs109);
  sf_mex_destroy(&c63_rhs110);
  sf_mex_destroy(&c63_lhs110);
  sf_mex_destroy(&c63_rhs111);
  sf_mex_destroy(&c63_lhs111);
  sf_mex_destroy(&c63_rhs112);
  sf_mex_destroy(&c63_lhs112);
  sf_mex_destroy(&c63_rhs113);
  sf_mex_destroy(&c63_lhs113);
  sf_mex_destroy(&c63_rhs114);
  sf_mex_destroy(&c63_lhs114);
  sf_mex_destroy(&c63_rhs115);
  sf_mex_destroy(&c63_lhs115);
  sf_mex_destroy(&c63_rhs116);
  sf_mex_destroy(&c63_lhs116);
  sf_mex_destroy(&c63_rhs117);
  sf_mex_destroy(&c63_lhs117);
  sf_mex_destroy(&c63_rhs118);
  sf_mex_destroy(&c63_lhs118);
}

static void c63_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  int32_T c63_i10;
  static char_T c63_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c63_u[30];
  const mxArray *c63_y = NULL;
  int32_T c63_i11;
  static char_T c63_cv1[5] = { 'l', 'o', 'g', '1', '0' };

  char_T c63_b_u[5];
  const mxArray *c63_b_y = NULL;
  (void)chartInstance;
  for (c63_i10 = 0; c63_i10 < 30; c63_i10++) {
    c63_u[c63_i10] = c63_cv0[c63_i10];
  }

  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c63_i11 = 0; c63_i11 < 5; c63_i11++) {
    c63_b_u[c63_i11] = c63_cv1[c63_i11];
  }

  c63_b_y = NULL;
  sf_mex_assign(&c63_b_y, sf_mex_create("y", c63_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c63_y, 14, c63_b_y));
}

static void c63_realmax(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c63_eml_scalar_eg(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c63_interp1(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_varargin_3)
{
  return c63_interp1_work(chartInstance, c63_varargin_3);
}

static real_T c63_interp1_work(SFc63_TSE_PathInstanceStruct *chartInstance,
  real_T c63_xi)
{
  real_T c63_yi;
  int32_T c63_k;
  int32_T c63_b_k;
  real_T c63_x;
  boolean_T c63_b;
  int32_T c63_c_k;
  real_T c63_b_xi;
  real_T c63_xik;
  real_T c63_b_x;
  boolean_T c63_b_b;
  real_T c63_c_xi;
  int32_T c63_low_i;
  int32_T c63_low_ip1;
  int32_T c63_high_i;
  int32_T c63_b_low_i;
  int32_T c63_b_high_i;
  int32_T c63_mid_i;
  int32_T c63_n;
  real_T c63_xn;
  real_T c63_xnp1;
  real_T c63_A;
  real_T c63_B;
  real_T c63_c_x;
  real_T c63_y;
  real_T c63_d_x;
  real_T c63_b_y;
  real_T c63_e_x;
  real_T c63_c_y;
  real_T c63_r;
  real_T c63_onemr;
  static real_T c63_d_y[181] = { 9.52645662326835, 9.60043021879921,
    9.67095320547355, 9.73833740796616, 9.80285485370918, 9.86474426975119,
    9.92421630463018, 9.98145776420873, 10.0366350767945, 10.089897149933,
    10.1413777426924, 10.1911974488216, 10.239465364947, 10.2862805019933,
    10.3317329858409, 10.3759050838973, 10.4188720870185, 10.4607030705707,
    10.5014615539778, 10.5412060745832, 10.5799906888456, 10.6178654116384,
    10.6548766026051, 10.6910673070487, 10.7264775576255, 10.7611446421339,
    10.7951033418663, 10.8283861443269, 10.8610234335519, 10.8930436608058,
    10.9244734980307, 10.9553379761004, 10.9856606096484, 11.0154635100058,
    11.0447674875824, 11.0735921448526, 11.1019559609634, 11.129876368854,
    11.1573698256671, 11.184451877143, 11.2111372165998, 11.2374397390397,
    11.2633725908557, 11.2889482155604, 11.3141783959148, 11.3390742927899,
    11.3636464810622, 11.3879049828095, 11.4118592980471, 11.4355184332216,
    11.4588909276529, 11.4819848781019, 11.5048079616193, 11.527367456819,
    11.5496702637037, 11.57172292216, 11.5935316292289, 11.6151022552467,
    11.636440358945, 11.6575512015887, 11.6784408828318, 11.6991120966971,
    11.719573653894, 11.7398301334405, 11.7598859539001, 11.7797453809776,
    11.7994125346705, 11.8188913960076, 11.8381858134025, 11.857299508647,
    11.8762360825713, 11.8949990203901, 11.9135916967575, 11.9320173805479,
    11.9502792393817, 11.9683803439115, 11.9863236718835, 12.0041121119888,
    12.0217484675175, 12.0392354598262, 12.0565757316325, 12.0737718501451,
    12.090826310039, 12.1077415362869, 12.1245198868527, 12.1411636552568,
    12.1576750730193, 12.1740563119888, 12.1903094865631, 12.2064366558068,
    12.222439825473, 12.2383209499331, 12.2540819340203, 12.2697246347907,
    12.2852508632075, 12.3006623857508, 12.3159609259588, 12.3311481659018,
    12.346225747594, 12.3611952743459, 12.3760583120594, 12.39081639047,
    12.4054710043373, 12.4200236145874, 12.4344756494082, 12.4488285053018,
    12.4630835480942, 12.4772421139051, 12.4913055100805, 12.5052750160877,
    12.519151884377, 12.5329373412095, 12.5466325874537, 12.5602387993524,
    12.5737571292605, 12.587188706355, 12.6005346373199, 12.6137960070049,
    12.6269738790605, 12.6400692965509, 12.6530832825434, 12.6660168406787,
    12.6788709557191, 12.6916465940792, 12.7043447043369, 12.7169662177274,
    12.7295120486199, 12.741983094978, 12.7543802388048, 12.7667043465727,
    12.7789562696389, 12.7911368446473, 12.803246893917, 12.8152872258177,
    12.8272586351336, 12.8391619034149, 12.8509977993184, 12.8627670789368,
    12.8744704861181, 12.8861087527745, 12.8976825991815, 12.9091927342682,
    12.9206398558985, 12.9320246511427, 12.9433477965427, 12.954609958367,
    12.9658117928596, 12.9769539464805, 12.9880370561396, 12.9990617494234,
    13.0100286448147, 13.0209383519066, 13.0317914716095, 13.0425885963529,
    13.0533303102802, 13.0640171894395, 13.0746498019673, 13.0852287082683,
    13.0957544611898, 13.1062276061903, 13.1166486815051, 13.1270182183055,
    13.1373367408551, 13.1476047666609, 13.1578228066209, 13.1679913651669,
    13.1781109404042, 13.1881820242475, 13.1982051025526, 13.2081806552451,
    13.2181091564456, 13.2279910745918, 13.2378268725567, 13.2476170077649,
    13.2573619323044, 13.2670620930371, 13.2767179317055, 13.2863298850366,
    13.2958983848441, 13.3054238581265, 13.3149067271648 };

  real_T c63_y1;
  real_T c63_y2;
  int32_T exitg1;
  c63_eml_scalar_eg(chartInstance);
  c63_StringToMethodID(chartInstance);
  c63_intmin(chartInstance);
  c63_k = 1;
  do {
    exitg1 = 0;
    if (c63_k < 182) {
      c63_b_k = c63_k;
      c63_x = 200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c63_b_k), 1, 181, 1, 0) - 1);
      c63_b = muDoubleScalarIsNaN(c63_x);
      if (c63_b) {
        c63_b_eml_error(chartInstance);
        exitg1 = 1;
      } else {
        c63_k++;
      }
    } else {
      c63_intmin(chartInstance);
      for (c63_c_k = 2; c63_c_k < 182; c63_c_k++) {
        c63_b_k = c63_c_k;
        if (200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c63_b_k), 1, 181, 1, 0) - 1) <=
            200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)(c63_b_k - 1)), 1, 181, 1, 0) - 1))
        {
          c63_c_eml_error(chartInstance);
        }
      }

      c63_b_xi = c63_xi;
      c63_yi = rtNaN;
      c63_xik = c63_b_xi;
      c63_b_x = c63_xik;
      c63_b_b = muDoubleScalarIsNaN(c63_b_x);
      if (c63_b_b) {
      } else if (c63_xik > 2000.0) {
      } else if (c63_xik < 200.0) {
      } else {
        c63_c_xi = c63_xik;
        c63_low_i = 1;
        c63_low_ip1 = 1;
        c63_high_i = 181;
        while (c63_high_i > c63_low_ip1 + 1) {
          c63_b_low_i = c63_low_i;
          c63_b_high_i = c63_high_i;
          c63_mid_i = (c63_b_low_i + c63_b_high_i) >> 1;
          if (c63_c_xi >= 200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c63_mid_i), 1, 181, 1, 0)
               - 1)) {
            c63_low_i = c63_mid_i;
            c63_low_ip1 = c63_low_i;
          } else {
            c63_high_i = c63_mid_i;
          }
        }

        c63_n = c63_low_i;
        c63_xn = 200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c63_n), 1, 181, 1, 0) - 1);
        c63_xnp1 = 200.0 + 10.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c63_n + 1)), 1, 181, 1, 0) -
          1);
        c63_A = c63_xik - c63_xn;
        c63_B = c63_xnp1 - c63_xn;
        c63_c_x = c63_A;
        c63_y = c63_B;
        c63_d_x = c63_c_x;
        c63_b_y = c63_y;
        c63_e_x = c63_d_x;
        c63_c_y = c63_b_y;
        c63_r = c63_e_x / c63_c_y;
        c63_onemr = 1.0 - c63_r;
        c63_y1 = c63_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c63_n), 1, 181, 1, 0) - 1];
        c63_y2 = c63_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c63_n + 1)), 1, 181, 1, 0) - 1];
        if (c63_y1 == c63_y2) {
          c63_yi = c63_y1;
        } else {
          c63_yi = c63_onemr * c63_y1 + c63_r * c63_y2;
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c63_yi;
}

static void c63_StringToMethodID(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static int32_T c63_intmin(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static void c63_b_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  int32_T c63_i12;
  static char_T c63_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't',
    'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };

  char_T c63_u[21];
  const mxArray *c63_y = NULL;
  (void)chartInstance;
  for (c63_i12 = 0; c63_i12 < 21; c63_i12++) {
    c63_u[c63_i12] = c63_cv2[c63_i12];
  }

  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c63_y));
}

static void c63_c_eml_error(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  int32_T c63_i13;
  static char_T c63_cv3[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n',
    'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };

  char_T c63_u[35];
  const mxArray *c63_y = NULL;
  (void)chartInstance;
  for (c63_i13 = 0; c63_i13 < 35; c63_i13++) {
    c63_u[c63_i13] = c63_cv3[c63_i13];
  }

  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", c63_u, 10, 0U, 1U, 0U, 2, 1, 35),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c63_y));
}

static real_T c63_b_interp1(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_varargin_1[181], real_T c63_varargin_2[181], real_T c63_varargin_3)
{
  real_T c63_Vq;
  int32_T c63_i14;
  real_T c63_y[181];
  real_T c63_xi;
  int32_T c63_i15;
  real_T c63_x[181];
  int32_T c63_k;
  int32_T c63_b_k;
  real_T c63_b_x;
  boolean_T c63_b;
  int32_T c63_j1;
  int32_T c63_b_j1;
  real_T c63_xtmp;
  int32_T c63_c_k;
  real_T c63_b_xi;
  real_T c63_minx;
  real_T c63_maxx;
  real_T c63_xik;
  real_T c63_c_x;
  boolean_T c63_b_b;
  real_T c63_c_xi;
  int32_T c63_low_i;
  int32_T c63_low_ip1;
  int32_T c63_high_i;
  int32_T c63_b_low_i;
  int32_T c63_b_high_i;
  int32_T c63_mid_i;
  int32_T c63_n;
  real_T c63_xn;
  real_T c63_xnp1;
  real_T c63_A;
  real_T c63_B;
  real_T c63_d_x;
  real_T c63_b_y;
  real_T c63_e_x;
  real_T c63_c_y;
  real_T c63_f_x;
  real_T c63_d_y;
  real_T c63_r;
  real_T c63_onemr;
  real_T c63_y1;
  real_T c63_y2;
  int32_T exitg1;
  for (c63_i14 = 0; c63_i14 < 181; c63_i14++) {
    c63_y[c63_i14] = c63_varargin_2[c63_i14];
  }

  c63_xi = c63_varargin_3;
  for (c63_i15 = 0; c63_i15 < 181; c63_i15++) {
    c63_x[c63_i15] = c63_varargin_1[c63_i15];
  }

  c63_eml_scalar_eg(chartInstance);
  c63_StringToMethodID(chartInstance);
  c63_intmin(chartInstance);
  c63_k = 1;
  do {
    exitg1 = 0;
    if (c63_k < 182) {
      c63_b_k = c63_k;
      c63_b_x = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c63_b_k), 1, 181, 1, 0) - 1];
      c63_b = muDoubleScalarIsNaN(c63_b_x);
      if (c63_b) {
        c63_b_eml_error(chartInstance);
        exitg1 = 1;
      } else {
        c63_k++;
      }
    } else {
      if (c63_x[1] < c63_x[0]) {
        c63_intmin(chartInstance);
        for (c63_j1 = 1; c63_j1 < 91; c63_j1++) {
          c63_b_j1 = c63_j1;
          c63_xtmp = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c63_b_j1), 1, 181, 1, 0) - 1];
          c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c63_b_j1), 1, 181, 1, 0) - 1] =
            c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(182 - c63_b_j1)), 1, 181, 1, 0) - 1];
          c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(182 - c63_b_j1)), 1, 181, 1, 0) - 1] = c63_xtmp;
        }

        c63_b_flip(chartInstance, c63_y);
      }

      c63_intmin(chartInstance);
      for (c63_c_k = 2; c63_c_k < 182; c63_c_k++) {
        c63_b_k = c63_c_k;
        if (c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c63_b_k), 1, 181, 1, 0) - 1] <=
            c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c63_b_k - 1)), 1, 181, 1, 0) - 1]) {
          c63_c_eml_error(chartInstance);
        }
      }

      c63_b_xi = c63_xi;
      c63_Vq = rtNaN;
      c63_minx = c63_x[0];
      c63_maxx = c63_x[180];
      c63_xik = c63_b_xi;
      c63_c_x = c63_xik;
      c63_b_b = muDoubleScalarIsNaN(c63_c_x);
      if (c63_b_b) {
      } else if (c63_xik > c63_maxx) {
      } else if (c63_xik < c63_minx) {
      } else {
        c63_c_xi = c63_xik;
        c63_low_i = 1;
        c63_low_ip1 = 1;
        c63_high_i = 181;
        while (c63_high_i > c63_low_ip1 + 1) {
          c63_b_low_i = c63_low_i;
          c63_b_high_i = c63_high_i;
          c63_mid_i = (c63_b_low_i + c63_b_high_i) >> 1;
          if (c63_c_xi >= c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c63_mid_i), 1, 181, 1, 0) - 1]) {
            c63_low_i = c63_mid_i;
            c63_low_ip1 = c63_low_i;
          } else {
            c63_high_i = c63_mid_i;
          }
        }

        c63_n = c63_low_i;
        c63_xn = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c63_n), 1, 181, 1, 0) - 1];
        c63_xnp1 = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c63_n + 1)), 1, 181, 1, 0) - 1];
        c63_A = c63_xik - c63_xn;
        c63_B = c63_xnp1 - c63_xn;
        c63_d_x = c63_A;
        c63_b_y = c63_B;
        c63_e_x = c63_d_x;
        c63_c_y = c63_b_y;
        c63_f_x = c63_e_x;
        c63_d_y = c63_c_y;
        c63_r = c63_f_x / c63_d_y;
        c63_onemr = 1.0 - c63_r;
        c63_y1 = c63_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c63_n), 1, 181, 1, 0) - 1];
        c63_y2 = c63_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c63_n + 1)), 1, 181, 1, 0) - 1];
        if (c63_y1 == c63_y2) {
          c63_Vq = c63_y1;
        } else {
          c63_Vq = c63_onemr * c63_y1 + c63_r * c63_y2;
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c63_Vq;
}

static void c63_flip(SFc63_TSE_PathInstanceStruct *chartInstance, real_T c63_x
                     [181], real_T c63_b_x[181])
{
  int32_T c63_i16;
  for (c63_i16 = 0; c63_i16 < 181; c63_i16++) {
    c63_b_x[c63_i16] = c63_x[c63_i16];
  }

  c63_b_flip(chartInstance, c63_b_x);
}

static const mxArray *c63_d_sf_marshallOut(void *chartInstanceVoid, void
  *c63_inData)
{
  const mxArray *c63_mxArrayOutData = NULL;
  int32_T c63_u;
  const mxArray *c63_y = NULL;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_mxArrayOutData = NULL;
  c63_u = *(int32_T *)c63_inData;
  c63_y = NULL;
  sf_mex_assign(&c63_y, sf_mex_create("y", &c63_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c63_mxArrayOutData, c63_y, false);
  return c63_mxArrayOutData;
}

static int32_T c63_c_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId)
{
  int32_T c63_y;
  int32_T c63_i17;
  (void)chartInstance;
  sf_mex_import(c63_parentId, sf_mex_dup(c63_u), &c63_i17, 1, 6, 0U, 0, 0U, 0);
  c63_y = c63_i17;
  sf_mex_destroy(&c63_u);
  return c63_y;
}

static void c63_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c63_mxArrayInData, const char_T *c63_varName, void *c63_outData)
{
  const mxArray *c63_b_sfEvent;
  const char_T *c63_identifier;
  emlrtMsgIdentifier c63_thisId;
  int32_T c63_y;
  SFc63_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc63_TSE_PathInstanceStruct *)chartInstanceVoid;
  c63_b_sfEvent = sf_mex_dup(c63_mxArrayInData);
  c63_identifier = c63_varName;
  c63_thisId.fIdentifier = c63_identifier;
  c63_thisId.fParent = NULL;
  c63_y = c63_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c63_b_sfEvent),
    &c63_thisId);
  sf_mex_destroy(&c63_b_sfEvent);
  *(int32_T *)c63_outData = c63_y;
  sf_mex_destroy(&c63_mxArrayInData);
}

static uint8_T c63_d_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_b_is_active_c63_TSE_Path, const char_T
  *c63_identifier)
{
  uint8_T c63_y;
  emlrtMsgIdentifier c63_thisId;
  c63_thisId.fIdentifier = c63_identifier;
  c63_thisId.fParent = NULL;
  c63_y = c63_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c63_b_is_active_c63_TSE_Path), &c63_thisId);
  sf_mex_destroy(&c63_b_is_active_c63_TSE_Path);
  return c63_y;
}

static uint8_T c63_e_emlrt_marshallIn(SFc63_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c63_u, const emlrtMsgIdentifier *c63_parentId)
{
  uint8_T c63_y;
  uint8_T c63_u0;
  (void)chartInstance;
  sf_mex_import(c63_parentId, sf_mex_dup(c63_u), &c63_u0, 1, 3, 0U, 0, 0U, 0);
  c63_y = c63_u0;
  sf_mex_destroy(&c63_u);
  return c63_y;
}

static void c63_b_flip(SFc63_TSE_PathInstanceStruct *chartInstance, real_T
  c63_x[181])
{
  int32_T c63_k;
  int32_T c63_b_k;
  real_T c63_tmp;
  c63_intmin(chartInstance);
  for (c63_k = 1; c63_k < 91; c63_k++) {
    c63_b_k = c63_k;
    c63_tmp = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c63_b_k), 1, 181, 1, 0) - 1];
    c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c63_b_k), 1, 181, 1, 0) - 1] = c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(182 - c63_b_k)), 1, 181, 1, 0)
      - 1];
    c63_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)(182 - c63_b_k)), 1, 181, 1, 0) - 1] = c63_tmp;
  }
}

static void init_dsm_address_info(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc63_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c63_f = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c63_PRGT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c63_EFGT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c63_T5s = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c63_T41s = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c63_h5 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c63_Sfcn5 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c63_Sfcn41 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c63_DHT_T = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c63_TSE_Path_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3996658468U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1029609745U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1819019959U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2084336739U);
}

mxArray* sf_c63_TSE_Path_get_post_codegen_info(void);
mxArray *sf_c63_TSE_Path_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZgpheNPTAWcZuDNerNmFdF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c63_TSE_Path_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c63_TSE_Path_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c63_TSE_Path_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c63_TSE_Path_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c63_TSE_Path_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c63_TSE_Path(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[13],T\"DHT_T\",},{M[1],M[9],T\"Sfcn5\",},{M[1],M[5],T\"T5s\",},{M[1],M[8],T\"h5\",},{M[8],M[0],T\"is_active_c63_TSE_Path\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c63_TSE_Path_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc63_TSE_PathInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc63_TSE_PathInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _TSE_PathMachineNumber_,
           63,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           3,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_TSE_PathMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_TSE_PathMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _TSE_PathMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"f");
          _SFD_SET_DATA_PROPS(1,1,1,0,"PRGT");
          _SFD_SET_DATA_PROPS(2,1,1,0,"EFGT");
          _SFD_SET_DATA_PROPS(3,2,0,1,"T5s");
          _SFD_SET_DATA_PROPS(4,1,1,0,"T41s");
          _SFD_SET_DATA_PROPS(5,2,0,1,"h5");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Sfcn5");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Sfcn41");
          _SFD_SET_DATA_PROPS(8,2,0,1,"DHT_T");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,499);
        _SFD_CV_INIT_EML_IF(0,1,0,61,71,-1,87);
        _SFD_CV_INIT_EML_IF(0,1,1,380,388,412,443);
        _SFD_CV_INIT_EML_WHILE(0,1,0,264,281,447);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,64,71,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,384,388,-1,5);
        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,1,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"Ts_Sfcn_f",0,-1,245);
        _SFD_CV_INIT_SCRIPT_IF(0,0,168,174,198,229);
        _SFD_CV_INIT_SCRIPT_WHILE(0,0,52,70,233);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,171,174,-1,4);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"Sfcn_Ts",0,-1,6437);
        _SFD_CV_INIT_SCRIPT(2,1,5,0,0,1,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"gashi",0,-1,1123);
        _SFD_CV_INIT_SCRIPT_IF(2,0,118,137,-1,165);
        _SFD_CV_INIT_SCRIPT_IF(2,1,167,193,-1,226);
        _SFD_CV_INIT_SCRIPT_IF(2,2,249,271,-1,299);
        _SFD_CV_INIT_SCRIPT_IF(2,3,355,368,-1,388);
        _SFD_CV_INIT_SCRIPT_IF(2,4,390,405,-1,426);

        {
          static int caseStart[] = { 754, 641 };

          static int caseExprEnd[] = { 763, 647 };

          _SFD_CV_INIT_SCRIPT_SWITCH(2,0,610,632,1106,2,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,0,121,137,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,1,170,193,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,2,252,271,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,3,358,368,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,4,394,405,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)c63_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)c63_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)c63_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c63_sf_marshallOut,(MexInFcnForType)c63_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c63_f);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c63_PRGT);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c63_EFGT);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c63_T5s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c63_T41s);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c63_h5);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c63_Sfcn5);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c63_Sfcn41);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c63_DHT_T);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _TSE_PathMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6zDTO5L298G7N0BiVnhwHF";
}

static void sf_opaque_initialize_c63_TSE_Path(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc63_TSE_PathInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*)
    chartInstanceVar);
  initialize_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c63_TSE_Path(void *chartInstanceVar)
{
  enable_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c63_TSE_Path(void *chartInstanceVar)
{
  disable_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c63_TSE_Path(void *chartInstanceVar)
{
  sf_gateway_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c63_TSE_Path(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c63_TSE_Path(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c63_TSE_Path(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc63_TSE_PathInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_TSE_Path_optimization_info();
    }

    finalize_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc63_TSE_Path((SFc63_TSE_PathInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c63_TSE_Path(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c63_TSE_Path((SFc63_TSE_PathInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c63_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_TSE_Path_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      63);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,63,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,63,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,63);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,63,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,63,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,63);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(137630843U));
  ssSetChecksum1(S,(975151119U));
  ssSetChecksum2(S,(1070914121U));
  ssSetChecksum3(S,(2096467068U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c63_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c63_TSE_Path(SimStruct *S)
{
  SFc63_TSE_PathInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc63_TSE_PathInstanceStruct *)utMalloc(sizeof
    (SFc63_TSE_PathInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc63_TSE_PathInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c63_TSE_Path;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c63_TSE_Path;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c63_TSE_Path;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c63_TSE_Path;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c63_TSE_Path;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c63_TSE_Path;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c63_TSE_Path;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c63_TSE_Path;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c63_TSE_Path;
  chartInstance->chartInfo.mdlStart = mdlStart_c63_TSE_Path;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c63_TSE_Path;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c63_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c63_TSE_Path(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c63_TSE_Path(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c63_TSE_Path(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c63_TSE_Path_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
