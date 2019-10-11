/* Include files */

#include <stddef.h>
#include "blas.h"
#include "GTF_EnginePath_TwoSpool_sfun.h"
#include "c4_GTF_EnginePath_TwoSpool.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GTF_EnginePath_TwoSpool_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[30] = { "d_Compr_Z1", "d_Compr_Z2",
  "d_Compr_Z3", "d_Compr_Z", "HPT_Cool_NGV_W", "HPT_Cool_PT_W", "LPT_Cool_NGV_W",
  "LPT_Cool_PT_W", "f", "h24", "Compr_PR_Z1", "Tt_Z1", "h_Z1", "Compr_PR_Z2",
  "h_Z2", "Compr_PR_Z3", "h_Z3", "h3", "W3", "nargin", "nargout", "W24", "PR",
  "Eff", "Tt24", "Deflate", "Tt_Z2", "Tt_Z3", "Tt3", "Load_Compr" };

static const char * c4_b_debug_family_names[9] = { "b_FuelAirRatio", "TE", "Hia",
  "Hif", "nargin", "nargout", "T", "FuelAirRatio", "Hi" };

static const char * c4_c_debug_family_names[18] = { "amw", "R_eng",
  "b_FuelAirRatio", "Cpcal", "TO", "T", "TE", "Cpa", "Cpf", "nargin", "nargout",
  "TI", "FAR", "PRK", "Eff", "Cp", "k", "R" };

static const char * c4_d_debug_family_names[8] = { "kg", "nargin", "nargout",
  "Tt_in", "f", "ComprPR", "ComprEff", "Tt_out" };

/* Function Declarations */
static void initialize_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initialize_params_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void enable_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void disable_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void set_sim_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c4_st);
static void finalize_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void sf_gateway_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void mdl_start_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c4_chartstep_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initSimStructsc4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static real_T c4_gashi(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
  real_T c4_T, real_T c4_FuelAirRatio);
static real_T c4_GasTt(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
  real_T c4_Tt_in, real_T c4_f, real_T c4_ComprPR, real_T c4_ComprEff);
static void c4_gasstate(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c4_TI, real_T c4_FAR, real_T c4_PRK, real_T c4_b_Eff,
  real_T *c4_Cp, real_T *c4_k, real_T *c4_R);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c4_b_Load_Compr, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_eml_scalar_eg(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void c4_eml_error(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static real_T c4_mpower(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c4_a, real_T c4_b);
static void c4_b_eml_error(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_b_is_active_c4_GTF_EnginePath_TwoSpool, const
  char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_GTF_EnginePath_TwoSpool = 0U;
}

static void initialize_params_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(5, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_Load_Compr;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *chartInstance->c4_Tt3;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *chartInstance->c4_Tt_Z2;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *chartInstance->c4_Tt_Z3;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_active_c4_GTF_EnginePath_TwoSpool;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_Load_Compr = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "Load_Compr");
  *chartInstance->c4_Tt3 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "Tt3");
  *chartInstance->c4_Tt_Z2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "Tt_Z2");
  *chartInstance->c4_Tt_Z3 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "Tt_Z3");
  chartInstance->c4_is_active_c4_GTF_EnginePath_TwoSpool = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
     "is_active_c4_GTF_EnginePath_TwoSpool");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_GTF_EnginePath_TwoSpool(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_W24, 0U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_GTF_EnginePath_TwoSpool(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GTF_EnginePath_TwoSpoolMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Tt_Z2, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Tt_Z3, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_PR, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Tt3, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Eff, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Tt24, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Load_Compr, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Deflate, 8U);
}

static void mdl_start_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_chartstep_c4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_b_W24;
  real_T c4_b_PR;
  real_T c4_b_Eff;
  real_T c4_b_Tt24;
  real_T c4_b_Deflate;
  uint32_T c4_debug_family_var_map[30];
  real_T c4_d_Compr_Z1;
  real_T c4_d_Compr_Z2;
  real_T c4_d_Compr_Z3;
  real_T c4_d_Compr_Z;
  real_T c4_HPT_Cool_NGV_W;
  real_T c4_HPT_Cool_PT_W;
  real_T c4_LPT_Cool_NGV_W;
  real_T c4_LPT_Cool_PT_W;
  real_T c4_f;
  real_T c4_h24;
  real_T c4_Compr_PR_Z1;
  real_T c4_Tt_Z1;
  real_T c4_h_Z1;
  real_T c4_Compr_PR_Z2;
  real_T c4_h_Z2;
  real_T c4_Compr_PR_Z3;
  real_T c4_h_Z3;
  real_T c4_h3;
  real_T c4_W3;
  real_T c4_nargin = 5.0;
  real_T c4_nargout = 4.0;
  real_T c4_b_Tt_Z2;
  real_T c4_b_Tt_Z3;
  real_T c4_b_Tt3;
  real_T c4_b_Load_Compr;
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  real_T c4_d_a;
  real_T c4_ar;
  real_T c4_e_a;
  real_T c4_f_a;
  real_T c4_g_a;
  real_T c4_b_ak;
  real_T c4_h_a;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_i_a;
  real_T c4_j_a;
  real_T c4_k_a;
  real_T c4_c_ak;
  real_T c4_l_a;
  real_T c4_b_ar;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *chartInstance->c4_W24;
  c4_b_hoistedGlobal = *chartInstance->c4_PR;
  c4_c_hoistedGlobal = *chartInstance->c4_Eff;
  c4_d_hoistedGlobal = *chartInstance->c4_Tt24;
  c4_e_hoistedGlobal = *chartInstance->c4_Deflate;
  c4_b_W24 = c4_hoistedGlobal;
  c4_b_PR = c4_b_hoistedGlobal;
  c4_b_Eff = c4_c_hoistedGlobal;
  c4_b_Tt24 = c4_d_hoistedGlobal;
  c4_b_Deflate = c4_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_d_Compr_Z1, 0U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_d_Compr_Z2, 1U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_d_Compr_Z3, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_d_Compr_Z, 3U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_HPT_Cool_NGV_W, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_HPT_Cool_PT_W, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_LPT_Cool_NGV_W, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_LPT_Cool_PT_W, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_f, 8U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h24, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Compr_PR_Z1, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Tt_Z1, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_Z1, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Compr_PR_Z2, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_Z2, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Compr_PR_Z3, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_Z3, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h3, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_W3, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 19U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 20U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_W24, 21U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_PR, 22U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Eff, 23U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Tt24, 24U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Deflate, 25U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Tt_Z2, 26U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Tt_Z3, 27U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Tt3, 28U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Load_Compr, 29U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_d_Compr_Z1 = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_d_Compr_Z2 = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_d_Compr_Z3 = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_d_Compr_Z = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_HPT_Cool_NGV_W = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_HPT_Cool_PT_W = 0.06;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_LPT_Cool_NGV_W = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_LPT_Cool_PT_W = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_f = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_h24 = c4_gashi(chartInstance, c4_b_Tt24, 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_a = c4_b_PR;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  if (c4_ak < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_d_a = c4_ak;
  c4_eml_scalar_eg(chartInstance);
  c4_ar = c4_d_a;
  c4_Compr_PR_Z1 = muDoubleScalarPower(c4_ar, 0.33333333333333331);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_Tt_Z1 = c4_GasTt(chartInstance, c4_b_Tt24, 0.0, c4_Compr_PR_Z1, c4_b_Eff);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_h_Z1 = c4_gashi(chartInstance, c4_Tt_Z1, 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
  c4_e_a = c4_b_PR;
  c4_f_a = c4_e_a;
  c4_g_a = c4_f_a;
  c4_eml_scalar_eg(chartInstance);
  c4_b_ak = c4_g_a;
  if (c4_b_ak < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_h_a = c4_b_ak;
  c4_eml_scalar_eg(chartInstance);
  c4_x = c4_h_a;
  c4_Compr_PR_Z2 = c4_x;
  if (c4_Compr_PR_Z2 < 0.0) {
    c4_b_eml_error(chartInstance);
  }

  c4_b_x = c4_Compr_PR_Z2;
  c4_Compr_PR_Z2 = c4_b_x;
  c4_Compr_PR_Z2 = muDoubleScalarSqrt(c4_Compr_PR_Z2);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
  c4_b_Tt_Z2 = c4_GasTt(chartInstance, c4_b_Tt24, 0.0, c4_Compr_PR_Z2, c4_b_Eff);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
  c4_h_Z2 = c4_gashi(chartInstance, c4_b_Tt_Z2, 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
  c4_i_a = c4_b_PR;
  c4_j_a = c4_i_a;
  c4_k_a = c4_j_a;
  c4_eml_scalar_eg(chartInstance);
  c4_c_ak = c4_k_a;
  if (c4_c_ak < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_l_a = c4_c_ak;
  c4_eml_scalar_eg(chartInstance);
  c4_b_ar = c4_l_a;
  c4_Compr_PR_Z3 = muDoubleScalarPower(c4_b_ar, 0.66666666666666663);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  c4_b_Tt_Z3 = c4_GasTt(chartInstance, c4_b_Tt24, 0.0, c4_Compr_PR_Z3, c4_b_Eff);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 31);
  c4_h_Z3 = c4_gashi(chartInstance, c4_b_Tt_Z3, 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
  c4_b_Tt3 = c4_GasTt(chartInstance, c4_b_Tt24, 0.0, c4_b_PR, c4_b_Eff);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
  c4_h3 = c4_gashi(chartInstance, c4_b_Tt3, 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
  c4_W3 = c4_b_W24 * (((((1.0 - c4_b_Deflate) - c4_HPT_Cool_NGV_W) -
                        c4_HPT_Cool_PT_W) - c4_LPT_Cool_NGV_W) -
                      c4_LPT_Cool_PT_W);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
  c4_b_Load_Compr = c4_b_W24 * ((((c4_h_Z1 - c4_h24) + (c4_h_Z2 - c4_h_Z1) *
    (1.0 - c4_b_Deflate)) + (c4_h_Z3 - c4_h_Z2) * ((1.0 - c4_b_Deflate) -
    c4_LPT_Cool_PT_W)) + (c4_h3 - c4_h_Z3) * (((1.0 - c4_b_Deflate) -
    c4_LPT_Cool_PT_W) - c4_LPT_Cool_NGV_W));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c4_Tt_Z2 = c4_b_Tt_Z2;
  *chartInstance->c4_Tt_Z3 = c4_b_Tt_Z3;
  *chartInstance->c4_Tt3 = c4_b_Tt3;
  *chartInstance->c4_Load_Compr = c4_b_Load_Compr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_GTF_EnginePath_TwoSpool
  (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c4_gashi(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
  real_T c4_T, real_T c4_FuelAirRatio)
{
  real_T c4_Hi;
  uint32_T c4_debug_family_var_map[9];
  real_T c4_b_FuelAirRatio;
  real_T c4_TE;
  real_T c4_Hia;
  real_T c4_Hif;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_b_A;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_c_A;
  real_T c4_B;
  real_T c4_g_x;
  real_T c4_y;
  real_T c4_h_x;
  real_T c4_b_y;
  real_T c4_i_x;
  real_T c4_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_FuelAirRatio, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_TE, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Hia, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Hif, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_T, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_FuelAirRatio, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Hi, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  if (CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c4_FuelAirRatio, 0.0, -1,
        2U, c4_FuelAirRatio < 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
    c4_FuelAirRatio = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  if (CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c4_FuelAirRatio,
        0.067623, -1, 4U, c4_FuelAirRatio > 0.067623))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
    c4_FuelAirRatio = 0.067623;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 16);
  if (CV_SCRIPT_IF(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c4_FuelAirRatio, 0.0, -1,
        0U, c4_FuelAirRatio == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 17);
    c4_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_A = c4_T * 9.0;
  c4_x = c4_A;
  c4_b_x = c4_x;
  c4_c_x = c4_b_x;
  c4_TE = c4_c_x / 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 22);
  if (CV_SCRIPT_IF(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c4_TE, 300.0, -1, 2U,
        c4_TE < 300.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 23);
    c4_TE = 300.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 26);
  if (CV_SCRIPT_IF(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c4_TE, 4000.0, -1, 4U,
        c4_TE > 4000.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 27);
    c4_TE = 4000.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 31);
  c4_Hia = (((((((1.2644425E-26 * c4_TE - 2.0752522E-22) * c4_TE + 1.270263E-18)
                * c4_TE - 3.0256518E-15) * c4_TE - 1.6794594E-12) * c4_TE +
              2.1839826E-8) * c4_TE - 2.576844E-5) * c4_TE + 0.25020051) * c4_TE
    - 1.7558886;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 33);
  switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c4_b_FuelAirRatio)) {
   case 1:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 38);
    c4_Hi = c4_Hia * 2.3254259;
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 42);
    c4_Hif = (((((((9.0848388E-26 * c4_TE - 1.9050949E-21) * c4_TE +
                   1.7021525E-17) * c4_TE - 8.4102208E-14) * c4_TE +
                 2.4921698E-10) * c4_TE - 4.5906332E-7) * c4_TE + 0.0006129315) *
              c4_TE + 0.073816638) * c4_TE + 30.58153;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 43);
    c4_c_A = c4_Hia + c4_FuelAirRatio * c4_Hif;
    c4_B = 1.0 + c4_FuelAirRatio;
    c4_g_x = c4_c_A;
    c4_y = c4_B;
    c4_h_x = c4_g_x;
    c4_b_y = c4_y;
    c4_i_x = c4_h_x;
    c4_c_y = c4_b_y;
    c4_Hif = c4_i_x / c4_c_y;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 46);
    c4_Hi = c4_Hif * 2.3254259;
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 48);
  c4_b_A = c4_TE * 5.0;
  c4_d_x = c4_b_A;
  c4_e_x = c4_d_x;
  c4_f_x = c4_e_x;
  c4_T = c4_f_x / 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  return c4_Hi;
}

static real_T c4_GasTt(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
  real_T c4_Tt_in, real_T c4_f, real_T c4_ComprPR, real_T c4_ComprEff)
{
  real_T c4_Tt_out;
  uint32_T c4_debug_family_var_map[8];
  real_T c4_kg;
  real_T c4_nargin = 4.0;
  real_T c4_nargout = 1.0;
  real_T c4_unusedU1;
  real_T c4_b_kg;
  real_T c4_unusedU0;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d_y;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_d_x;
  real_T c4_e_y;
  real_T c4_e_x;
  real_T c4_f_y;
  real_T c4_f_x;
  real_T c4_g_y;
  real_T c4_h_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_d_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_kg, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Tt_in, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ComprPR, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ComprEff, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Tt_out, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 2);
  c4_gasstate(chartInstance, c4_Tt_in, c4_f, c4_ComprPR, c4_ComprEff,
              &c4_unusedU0, &c4_b_kg, &c4_unusedU1);
  c4_kg = c4_b_kg;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_A = c4_kg - 1.0;
  c4_B = c4_kg;
  c4_x = c4_A;
  c4_y = c4_B;
  c4_b_x = c4_x;
  c4_b_y = c4_y;
  c4_c_x = c4_b_x;
  c4_c_y = c4_b_y;
  c4_d_y = c4_c_x / c4_c_y;
  c4_b_A = c4_mpower(chartInstance, c4_ComprPR, c4_d_y) - 1.0;
  c4_b_B = c4_ComprEff;
  c4_d_x = c4_b_A;
  c4_e_y = c4_b_B;
  c4_e_x = c4_d_x;
  c4_f_y = c4_e_y;
  c4_f_x = c4_e_x;
  c4_g_y = c4_f_y;
  c4_h_y = c4_f_x / c4_g_y;
  c4_Tt_out = (c4_h_y + 1.0) * c4_Tt_in;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  return c4_Tt_out;
}

static void c4_gasstate(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c4_TI, real_T c4_FAR, real_T c4_PRK, real_T c4_b_Eff,
  real_T *c4_Cp, real_T *c4_k, real_T *c4_R)
{
  uint32_T c4_debug_family_var_map[18];
  real_T c4_amw;
  real_T c4_R_eng;
  real_T c4_b_FuelAirRatio;
  real_T c4_Cpcal;
  real_T c4_TO;
  real_T c4_T;
  real_T c4_TE;
  real_T c4_Cpa;
  real_T c4_Cpf;
  real_T c4_nargin = 4.0;
  real_T c4_nargout = 3.0;
  real_T c4_B;
  real_T c4_y;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_d_y;
  real_T c4_A;
  real_T c4_b_B;
  real_T c4_c_x;
  real_T c4_e_y;
  real_T c4_d_x;
  real_T c4_f_y;
  real_T c4_e_x;
  real_T c4_g_y;
  real_T c4_b_A;
  real_T c4_c_B;
  real_T c4_f_x;
  real_T c4_h_y;
  real_T c4_g_x;
  real_T c4_i_y;
  real_T c4_h_x;
  real_T c4_j_y;
  real_T c4_k_y;
  real_T c4_c_A;
  real_T c4_d_B;
  real_T c4_i_x;
  real_T c4_l_y;
  real_T c4_j_x;
  real_T c4_m_y;
  real_T c4_k_x;
  real_T c4_n_y;
  real_T c4_o_y;
  real_T c4_d_A;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_e_A;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_f_A;
  real_T c4_e_B;
  real_T c4_r_x;
  real_T c4_p_y;
  real_T c4_s_x;
  real_T c4_q_y;
  real_T c4_t_x;
  real_T c4_r_y;
  real_T c4_g_A;
  real_T c4_f_B;
  real_T c4_u_x;
  real_T c4_s_y;
  real_T c4_v_x;
  real_T c4_t_y;
  real_T c4_w_x;
  real_T c4_u_y;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_c_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_amw, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_R_eng, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_FuelAirRatio, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Cpcal, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_TO, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_T, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_TE, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Cpa, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Cpf, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_TI, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_FAR, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_PRK, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Eff, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Cp, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_k, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_R, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 4);
  c4_amw = 28.97 - 0.946186 * c4_FAR;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 5);
  c4_B = c4_amw;
  c4_y = c4_B;
  c4_b_y = c4_y;
  c4_c_y = c4_b_y;
  c4_R_eng = 1.986375 / c4_c_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 6);
  *c4_R = c4_R_eng * 4185.7666;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 8);
  if (CV_SCRIPT_IF(2, 0, CV_RELATIONAL_EVAL(14U, 2U, 0, c4_FAR, 0.0, -1, 2U,
        c4_FAR < 0.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 9);
    c4_FAR = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 11);
  if (CV_SCRIPT_IF(2, 1, CV_RELATIONAL_EVAL(14U, 2U, 1, c4_FAR, 0.067623, -1, 4U,
        c4_FAR > 0.067623))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 12);
    c4_FAR = 0.067623;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 15);
  c4_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 16);
  if (CV_SCRIPT_IF(2, 2, CV_RELATIONAL_EVAL(14U, 2U, 2, c4_FAR, 0.0, -1, 0U,
        c4_FAR == 0.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 17);
    c4_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 20);
  *c4_Cp = 1100.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 21);
  c4_Cpcal = 1200.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 23);
  do {
    exitg1 = 0;
    c4_x = *c4_Cp - c4_Cpcal;
    c4_b_x = c4_x;
    c4_d_y = muDoubleScalarAbs(c4_b_x);
    if (CV_SCRIPT_WHILE(2, 0, c4_d_y - 1.0E-7 * c4_Cpcal > 0.0)) {
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 24);
      *c4_Cp = c4_Cpcal;
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 25);
      c4_A = *c4_Cp;
      c4_b_B = *c4_Cp - *c4_R;
      c4_c_x = c4_A;
      c4_e_y = c4_b_B;
      c4_d_x = c4_c_x;
      c4_f_y = c4_e_y;
      c4_e_x = c4_d_x;
      c4_g_y = c4_f_y;
      *c4_k = c4_e_x / c4_g_y;
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 26);
      c4_b_A = *c4_k - 1.0;
      c4_c_B = *c4_k;
      c4_f_x = c4_b_A;
      c4_h_y = c4_c_B;
      c4_g_x = c4_f_x;
      c4_i_y = c4_h_y;
      c4_h_x = c4_g_x;
      c4_j_y = c4_i_y;
      c4_k_y = c4_h_x / c4_j_y;
      c4_c_A = c4_mpower(chartInstance, c4_PRK, c4_k_y) - 1.0;
      c4_d_B = c4_b_Eff;
      c4_i_x = c4_c_A;
      c4_l_y = c4_d_B;
      c4_j_x = c4_i_x;
      c4_m_y = c4_l_y;
      c4_k_x = c4_j_x;
      c4_n_y = c4_m_y;
      c4_o_y = c4_k_x / c4_n_y;
      c4_TO = c4_TI * (1.0 + c4_o_y);
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 27);
      c4_d_A = c4_TI + c4_TO;
      c4_l_x = c4_d_A;
      c4_m_x = c4_l_x;
      c4_n_x = c4_m_x;
      c4_T = c4_n_x / 2.0;
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 29);
      c4_e_A = c4_T * 9.0;
      c4_o_x = c4_e_A;
      c4_p_x = c4_o_x;
      c4_q_x = c4_p_x;
      c4_TE = c4_q_x / 5.0;
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 30);
      if (CV_SCRIPT_IF(2, 3, CV_RELATIONAL_EVAL(14U, 2U, 3, c4_TE, 300.0, -1, 2U,
            c4_TE < 300.0))) {
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 31);
        c4_TE = 300.0;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 33);
      if (CV_SCRIPT_IF(2, 4, CV_RELATIONAL_EVAL(14U, 2U, 4, c4_TE, 4000.0, -1,
            4U, c4_TE > 4000.0))) {
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 34);
        c4_TE = 4000.0;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 38);
      c4_Cpa = ((((((1.011554E-25 * c4_TE - 1.452677E-21) * c4_TE +
                    7.6215767E-18) * c4_TE - 1.5128259E-14) * c4_TE -
                  6.7178376E-12) * c4_TE + 6.5519486E-8) * c4_TE - 5.1536879E-5)
        * c4_TE + 0.25020051;
      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 40);
      switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c4_b_FuelAirRatio))
      {
       case 1:
        CV_SCRIPT_SWITCH(2, 0, 1);
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 44);
        c4_Cpcal = c4_Cpa * 4185.7666;
        break;

       default:
        CV_SCRIPT_SWITCH(2, 0, 0);
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 47);
        c4_Cpf = ((((((7.267871E-25 * c4_TE - 1.3335668E-20) * c4_TE +
                      1.0212913E-16) * c4_TE - 4.2051104E-13) * c4_TE +
                    9.9686793E-10) * c4_TE - 1.3771901E-6) * c4_TE + 0.001225863)
          * c4_TE + 0.073816638;
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 48);
        c4_g_A = c4_Cpa + c4_FAR * c4_Cpf;
        c4_f_B = 1.0 + c4_FAR;
        c4_u_x = c4_g_A;
        c4_s_y = c4_f_B;
        c4_v_x = c4_u_x;
        c4_t_y = c4_s_y;
        c4_w_x = c4_v_x;
        c4_u_y = c4_t_y;
        c4_Cpf = c4_w_x / c4_u_y;
        _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 51);
        c4_Cpcal = c4_Cpf * 4185.7666;
        break;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 23);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 57);
  c4_f_A = *c4_Cp;
  c4_e_B = *c4_Cp - *c4_R;
  c4_r_x = c4_f_A;
  c4_p_y = c4_e_B;
  c4_s_x = c4_r_x;
  c4_q_y = c4_p_y;
  c4_t_x = c4_s_x;
  c4_r_y = c4_q_y;
  *c4_k = c4_t_x / c4_r_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, 59);
  *c4_Cp = c4_Cpcal;
  _SFD_SCRIPT_CALL(2U, chartInstance->c4_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\gashi.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 1U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\GasTt.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 2U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\gasstate.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c4_b_Load_Compr, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Load_Compr),
    &c4_thisId);
  sf_mex_destroy(&c4_b_Load_Compr);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_Load_Compr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c4_b_Load_Compr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Load_Compr),
    &c4_thisId);
  sf_mex_destroy(&c4_b_Load_Compr);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 35, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  const mxArray *c4_rhs14 = NULL;
  const mxArray *c4_lhs14 = NULL;
  const mxArray *c4_rhs15 = NULL;
  const mxArray *c4_lhs15 = NULL;
  const mxArray *c4_rhs16 = NULL;
  const mxArray *c4_lhs16 = NULL;
  const mxArray *c4_rhs17 = NULL;
  const mxArray *c4_lhs17 = NULL;
  const mxArray *c4_rhs18 = NULL;
  const mxArray *c4_lhs18 = NULL;
  const mxArray *c4_rhs19 = NULL;
  const mxArray *c4_lhs19 = NULL;
  const mxArray *c4_rhs20 = NULL;
  const mxArray *c4_lhs20 = NULL;
  const mxArray *c4_rhs21 = NULL;
  const mxArray *c4_lhs21 = NULL;
  const mxArray *c4_rhs22 = NULL;
  const mxArray *c4_lhs22 = NULL;
  const mxArray *c4_rhs23 = NULL;
  const mxArray *c4_lhs23 = NULL;
  const mxArray *c4_rhs24 = NULL;
  const mxArray *c4_lhs24 = NULL;
  const mxArray *c4_rhs25 = NULL;
  const mxArray *c4_lhs25 = NULL;
  const mxArray *c4_rhs26 = NULL;
  const mxArray *c4_lhs26 = NULL;
  const mxArray *c4_rhs27 = NULL;
  const mxArray *c4_lhs27 = NULL;
  const mxArray *c4_rhs28 = NULL;
  const mxArray *c4_lhs28 = NULL;
  const mxArray *c4_rhs29 = NULL;
  const mxArray *c4_lhs29 = NULL;
  const mxArray *c4_rhs30 = NULL;
  const mxArray *c4_lhs30 = NULL;
  const mxArray *c4_rhs31 = NULL;
  const mxArray *c4_lhs31 = NULL;
  const mxArray *c4_rhs32 = NULL;
  const mxArray *c4_lhs32 = NULL;
  const mxArray *c4_rhs33 = NULL;
  const mxArray *c4_lhs33 = NULL;
  const mxArray *c4_rhs34 = NULL;
  const mxArray *c4_lhs34 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("gashi"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gashi.m"), "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1428734872U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gashi.m"), "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mpower"), "name", "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("ismatrix"), "name", "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("power"), "name", "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395303306U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c4_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c4_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c4_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c4_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c4_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c4_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c4_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c4_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("GasTt"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/GasTt.m"), "resolved", "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1460024766U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c4_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/GasTt.m"), "context", "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("gasstate"), "name", "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "resolved", "resolved",
                  24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1460024745U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c4_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c4_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("abs"), "name", "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c4_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c4_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c4_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mpower"), "name", "name", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c4_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/GasTt.m"), "context", "context", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c4_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/GasTt.m"), "context", "context", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mpower"), "name", "name", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c4_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("sqrt"), "name", "name", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c4_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c4_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286797138U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c4_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs34), "lhs", "lhs",
                  34);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
  sf_mex_destroy(&c4_rhs14);
  sf_mex_destroy(&c4_lhs14);
  sf_mex_destroy(&c4_rhs15);
  sf_mex_destroy(&c4_lhs15);
  sf_mex_destroy(&c4_rhs16);
  sf_mex_destroy(&c4_lhs16);
  sf_mex_destroy(&c4_rhs17);
  sf_mex_destroy(&c4_lhs17);
  sf_mex_destroy(&c4_rhs18);
  sf_mex_destroy(&c4_lhs18);
  sf_mex_destroy(&c4_rhs19);
  sf_mex_destroy(&c4_lhs19);
  sf_mex_destroy(&c4_rhs20);
  sf_mex_destroy(&c4_lhs20);
  sf_mex_destroy(&c4_rhs21);
  sf_mex_destroy(&c4_lhs21);
  sf_mex_destroy(&c4_rhs22);
  sf_mex_destroy(&c4_lhs22);
  sf_mex_destroy(&c4_rhs23);
  sf_mex_destroy(&c4_lhs23);
  sf_mex_destroy(&c4_rhs24);
  sf_mex_destroy(&c4_lhs24);
  sf_mex_destroy(&c4_rhs25);
  sf_mex_destroy(&c4_lhs25);
  sf_mex_destroy(&c4_rhs26);
  sf_mex_destroy(&c4_lhs26);
  sf_mex_destroy(&c4_rhs27);
  sf_mex_destroy(&c4_lhs27);
  sf_mex_destroy(&c4_rhs28);
  sf_mex_destroy(&c4_lhs28);
  sf_mex_destroy(&c4_rhs29);
  sf_mex_destroy(&c4_lhs29);
  sf_mex_destroy(&c4_rhs30);
  sf_mex_destroy(&c4_lhs30);
  sf_mex_destroy(&c4_rhs31);
  sf_mex_destroy(&c4_lhs31);
  sf_mex_destroy(&c4_rhs32);
  sf_mex_destroy(&c4_lhs32);
  sf_mex_destroy(&c4_rhs33);
  sf_mex_destroy(&c4_lhs33);
  sf_mex_destroy(&c4_rhs34);
  sf_mex_destroy(&c4_lhs34);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static void c4_eml_scalar_eg(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_eml_error(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  int32_T c4_i0;
  static char_T c4_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[31];
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  for (c4_i0 = 0; c4_i0 < 31; c4_i0++) {
    c4_u[c4_i0] = c4_cv0[c4_i0];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c4_y));
}

static real_T c4_mpower(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c4_a, real_T c4_b)
{
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_ak;
  real_T c4_bk;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_ar;
  real_T c4_br;
  c4_b_a = c4_a;
  c4_b_b = c4_b;
  c4_c_a = c4_b_a;
  c4_c_b = c4_b_b;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  c4_bk = c4_c_b;
  if (c4_ak < 0.0) {
    c4_x = c4_bk;
    c4_b_x = c4_x;
    c4_b_x = muDoubleScalarFloor(c4_b_x);
    if (c4_b_x != c4_bk) {
      c4_eml_error(chartInstance);
    }
  }

  c4_d_a = c4_ak;
  c4_d_b = c4_bk;
  c4_eml_scalar_eg(chartInstance);
  c4_ar = c4_d_a;
  c4_br = c4_d_b;
  return muDoubleScalarPower(c4_ar, c4_br);
}

static void c4_b_eml_error(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  int32_T c4_i1;
  static char_T c4_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[30];
  const mxArray *c4_y = NULL;
  int32_T c4_i2;
  static char_T c4_cv2[4] = { 's', 'q', 'r', 't' };

  char_T c4_b_u[4];
  const mxArray *c4_b_y = NULL;
  (void)chartInstance;
  for (c4_i1 = 0; c4_i1 < 30; c4_i1++) {
    c4_u[c4_i1] = c4_cv1[c4_i1];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    c4_b_u[c4_i2] = c4_cv2[c4_i2];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c4_y, 14, c4_b_y));
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i3, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_b_is_active_c4_GTF_EnginePath_TwoSpool, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_GTF_EnginePath_TwoSpool), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_GTF_EnginePath_TwoSpool);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *
  chartInstance)
{
  chartInstance->c4_W24 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_Tt_Z2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_Tt_Z3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_PR = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c4_Tt3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_Eff = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_Tt24 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c4_Load_Compr = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c4_Deflate = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c4_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3608479735U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2851289270U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(478082648U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(702158412U);
}

mxArray* sf_c4_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
mxArray *sf_c4_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sgdZujAwLSjeDG5fINtgLC");
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
    mxArray* mxPostCodegenInfo =
      sf_c4_GTF_EnginePath_TwoSpool_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_GTF_EnginePath_TwoSpool_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_GTF_EnginePath_TwoSpool_jit_fallback_info(void)
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

mxArray *sf_c4_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_GTF_EnginePath_TwoSpool_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_GTF_EnginePath_TwoSpool(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[11],T\"Load_Compr\",},{M[1],M[5],T\"Tt3\",},{M[1],M[13],T\"Tt_Z2\",},{M[1],M[14],T\"Tt_Z3\",},{M[8],M[0],T\"is_active_c4_GTF_EnginePath_TwoSpool\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_GTF_EnginePath_TwoSpool_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GTF_EnginePath_TwoSpoolMachineNumber_,
           4,
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
        init_script_number_translation(_GTF_EnginePath_TwoSpoolMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_GTF_EnginePath_TwoSpoolMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _GTF_EnginePath_TwoSpoolMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"W24");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Tt_Z2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Tt_Z3");
          _SFD_SET_DATA_PROPS(3,1,1,0,"PR");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Tt3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Eff");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Tt24");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Load_Compr");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Deflate");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,915);
        _SFD_CV_INIT_SCRIPT(0,1,5,0,0,1,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"gashi",0,-1,1123);
        _SFD_CV_INIT_SCRIPT_IF(0,0,118,137,-1,165);
        _SFD_CV_INIT_SCRIPT_IF(0,1,167,193,-1,226);
        _SFD_CV_INIT_SCRIPT_IF(0,2,249,271,-1,299);
        _SFD_CV_INIT_SCRIPT_IF(0,3,355,368,-1,388);
        _SFD_CV_INIT_SCRIPT_IF(0,4,390,405,-1,426);

        {
          static int caseStart[] = { 754, 641 };

          static int caseExprEnd[] = { 763, 647 };

          _SFD_CV_INIT_SCRIPT_SWITCH(0,0,610,632,1106,2,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,121,137,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,170,193,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,2,252,271,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,3,358,368,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,4,394,405,-1,4);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"GasTt",0,-1,143);
        _SFD_CV_INIT_SCRIPT(2,1,5,0,0,1,0,1,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"gasstate",0,-1,1364);
        _SFD_CV_INIT_SCRIPT_IF(2,0,205,215,-1,234);
        _SFD_CV_INIT_SCRIPT_IF(2,1,235,252,-1,276);
        _SFD_CV_INIT_SCRIPT_IF(2,2,298,311,-1,339);
        _SFD_CV_INIT_SCRIPT_IF(2,3,544,558,-1,586);
        _SFD_CV_INIT_SCRIPT_IF(2,4,591,605,-1,634);
        _SFD_CV_INIT_SCRIPT_WHILE(2,0,367,408,1289);

        {
          static int caseStart[] = { 953, 846 };

          static int caseExprEnd[] = { 962, 852 };

          _SFD_CV_INIT_SCRIPT_SWITCH(2,0,816,838,1270,2,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,0,208,215,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,1,238,252,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,2,301,311,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,3,548,558,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,4,594,605,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_W24);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c4_Tt_Z2);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_Tt_Z3);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c4_PR);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c4_Tt3);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_Eff);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_Tt24);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_Load_Compr);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c4_Deflate);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _GTF_EnginePath_TwoSpoolMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "S7OjRIZ0Ko5SJHxAo1CyAF";
}

static void sf_opaque_initialize_c4_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
  initialize_c4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  enable_c4_GTF_EnginePath_TwoSpool((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  disable_c4_GTF_EnginePath_TwoSpool((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  sf_gateway_c4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_GTF_EnginePath_TwoSpool
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_GTF_EnginePath_TwoSpool(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c4_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GTF_EnginePath_TwoSpool_optimization_info();
    }

    finalize_c4_GTF_EnginePath_TwoSpool
      ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_GTF_EnginePath_TwoSpool
    ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_GTF_EnginePath_TwoSpool(SimStruct *S)
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
    initialize_params_c4_GTF_EnginePath_TwoSpool
      ((SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GTF_EnginePath_TwoSpool_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(916588733U));
  ssSetChecksum1(S,(2896208585U));
  ssSetChecksum2(S,(3815769048U));
  ssSetChecksum3(S,(2896936985U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct *)utMalloc(sizeof
    (SFc4_GTF_EnginePath_TwoSpoolInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_GTF_EnginePath_TwoSpoolInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_GTF_EnginePath_TwoSpool;
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

void c4_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_GTF_EnginePath_TwoSpool(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_GTF_EnginePath_TwoSpool_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
