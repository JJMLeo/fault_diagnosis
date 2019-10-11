/* Include files */

#include <stddef.h>
#include "blas.h"
#include "GTF_EnginePath_TwoSpool_sfun.h"
#include "c15_GTF_EnginePath_TwoSpool.h"
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
static const char * c15_debug_family_names[10] = { "ka", "Sigma_Inl", "Pt_in",
  "nargin", "nargout", "T_in", "P_in", "Ma", "Pt_out", "Tt_out" };

static const char * c15_b_debug_family_names[7] = { "Cp_p", "SitaCp_p", "nargin",
  "nargout", "Ts", "f", "Cp" };

static const char * c15_c_debug_family_names[4] = { "nargin", "nargout", "f",
  "R" };

static const char * c15_d_debug_family_names[5] = { "nargin", "nargout", "Ts",
  "f", "k" };

/* Function Declarations */
static void initialize_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initialize_params_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void enable_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void disable_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void set_sim_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_st);
static void finalize_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void sf_gateway_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void mdl_start_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c15_chartstep_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initSimStructsc15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static real_T c15_Cp(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
                     real_T c15_Ts, real_T c15_f);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c15_b_Tt_out, const char_T *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static real_T c15_mpower(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c15_a);
static void c15_eml_scalar_eg(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void c15_eml_error(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_c_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_d_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_b_is_active_c15_GTF_EnginePath_TwoSpool, const char_T *c15_identifier);
static uint8_T c15_e_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_GTF_EnginePath_TwoSpool = 0U;
}

static void initialize_params_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_b_hoistedGlobal;
  real_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  uint8_T c15_c_hoistedGlobal;
  uint8_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(3, 1), false);
  c15_hoistedGlobal = *chartInstance->c15_Pt_out;
  c15_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = *chartInstance->c15_Tt_out;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_c_hoistedGlobal = chartInstance->c15_is_active_c15_GTF_EnginePath_TwoSpool;
  c15_c_u = c15_c_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_st)
{
  const mxArray *c15_u;
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_u = sf_mex_dup(c15_st);
  *chartInstance->c15_Pt_out = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 0)), "Pt_out");
  *chartInstance->c15_Tt_out = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 1)), "Tt_out");
  chartInstance->c15_is_active_c15_GTF_EnginePath_TwoSpool =
    c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
    "is_active_c15_GTF_EnginePath_TwoSpool");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_GTF_EnginePath_TwoSpool(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_T_in, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_P_in, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Ma, 2U);
  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_GTF_EnginePath_TwoSpool(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GTF_EnginePath_TwoSpoolMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Pt_out, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Tt_out, 4U);
}

static void mdl_start_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c15_chartstep_c15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_hoistedGlobal;
  real_T c15_b_T_in;
  real_T c15_b_P_in;
  real_T c15_b_Ma;
  uint32_T c15_debug_family_var_map[10];
  real_T c15_ka;
  real_T c15_Sigma_Inl;
  real_T c15_Pt_in;
  real_T c15_nargin = 3.0;
  real_T c15_nargout = 2.0;
  real_T c15_b_Pt_out;
  real_T c15_b_Tt_out;
  real_T c15_Ts;
  real_T c15_f;
  uint32_T c15_b_debug_family_var_map[5];
  real_T c15_b_nargin = 2.0;
  real_T c15_b_nargout = 1.0;
  real_T c15_b_f;
  uint32_T c15_c_debug_family_var_map[4];
  real_T c15_c_nargin = 1.0;
  real_T c15_c_nargout = 1.0;
  real_T c15_R;
  real_T c15_A;
  real_T c15_B;
  real_T c15_x;
  real_T c15_y;
  real_T c15_b_x;
  real_T c15_b_y;
  real_T c15_c_x;
  real_T c15_c_y;
  real_T c15_b_A;
  real_T c15_d_x;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_d_y;
  real_T c15_c_A;
  real_T c15_b_B;
  real_T c15_g_x;
  real_T c15_e_y;
  real_T c15_h_x;
  real_T c15_f_y;
  real_T c15_i_x;
  real_T c15_g_y;
  real_T c15_h_y;
  real_T c15_a;
  real_T c15_b;
  real_T c15_b_a;
  real_T c15_b_b;
  real_T c15_c_a;
  real_T c15_c_b;
  real_T c15_ak;
  real_T c15_bk;
  real_T c15_j_x;
  real_T c15_k_x;
  real_T c15_d_a;
  real_T c15_d_b;
  real_T c15_ar;
  real_T c15_br;
  real_T c15_c;
  real_T c15_d_A;
  real_T c15_l_x;
  real_T c15_m_x;
  real_T c15_n_x;
  real_T c15_i_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = *chartInstance->c15_T_in;
  c15_b_hoistedGlobal = *chartInstance->c15_P_in;
  c15_c_hoistedGlobal = *chartInstance->c15_Ma;
  c15_b_T_in = c15_hoistedGlobal;
  c15_b_P_in = c15_b_hoistedGlobal;
  c15_b_Ma = c15_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_ka, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Sigma_Inl, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Pt_in, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 4U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_T_in, 5U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_P_in, 6U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_Ma, 7U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Pt_out, 8U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Tt_out, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 3);
  c15_Ts = c15_b_T_in;
  c15_f = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c15_d_debug_family_names,
    c15_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargin, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargout, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Ts, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_f, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_ka, 4U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 2);
  c15_b_f = c15_f;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c15_c_debug_family_names,
    c15_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_c_nargin, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_c_nargout, 1U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_f, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_R, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c15_sfEvent, 2);
  c15_R = (287.5 - 0.0099 * c15_b_f) + c15_b_f * 1.0E-7;
  _SFD_SCRIPT_CALL(2U, chartInstance->c15_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  c15_A = c15_Cp(chartInstance, c15_Ts, c15_f);
  c15_B = c15_Cp(chartInstance, c15_Ts, c15_f) - c15_R;
  c15_x = c15_A;
  c15_y = c15_B;
  c15_b_x = c15_x;
  c15_b_y = c15_y;
  c15_c_x = c15_b_x;
  c15_c_y = c15_b_y;
  c15_ka = c15_c_x / c15_c_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c15_b_Ma, 1.0, -1, 3U,
        c15_b_Ma <= 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 5);
    c15_Sigma_Inl = 0.99;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
    c15_Sigma_Inl = (0.88722 + 0.1717 * c15_b_Ma) - 0.08986 * c15_mpower
      (chartInstance, c15_b_Ma);
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 10);
  c15_b_A = c15_ka - 1.0;
  c15_d_x = c15_b_A;
  c15_e_x = c15_d_x;
  c15_f_x = c15_e_x;
  c15_d_y = c15_f_x / 2.0;
  c15_c_A = c15_ka;
  c15_b_B = c15_ka - 1.0;
  c15_g_x = c15_c_A;
  c15_e_y = c15_b_B;
  c15_h_x = c15_g_x;
  c15_f_y = c15_e_y;
  c15_i_x = c15_h_x;
  c15_g_y = c15_f_y;
  c15_h_y = c15_i_x / c15_g_y;
  c15_a = 1.0 + c15_d_y * c15_mpower(chartInstance, c15_b_Ma);
  c15_b = c15_h_y;
  c15_b_a = c15_a;
  c15_b_b = c15_b;
  c15_c_a = c15_b_a;
  c15_c_b = c15_b_b;
  c15_eml_scalar_eg(chartInstance);
  c15_ak = c15_c_a;
  c15_bk = c15_c_b;
  if (c15_ak < 0.0) {
    c15_j_x = c15_bk;
    c15_k_x = c15_j_x;
    c15_k_x = muDoubleScalarFloor(c15_k_x);
    if (c15_k_x != c15_bk) {
      c15_eml_error(chartInstance);
    }
  }

  c15_d_a = c15_ak;
  c15_d_b = c15_bk;
  c15_eml_scalar_eg(chartInstance);
  c15_ar = c15_d_a;
  c15_br = c15_d_b;
  c15_c = muDoubleScalarPower(c15_ar, c15_br);
  c15_Pt_in = c15_b_P_in * c15_c;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
  c15_d_A = c15_ka - 1.0;
  c15_l_x = c15_d_A;
  c15_m_x = c15_l_x;
  c15_n_x = c15_m_x;
  c15_i_y = c15_n_x / 2.0;
  c15_b_Tt_out = c15_b_T_in * (1.0 + c15_i_y * c15_mpower(chartInstance,
    c15_b_Ma));
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  c15_b_Pt_out = c15_Pt_in * c15_Sigma_Inl;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c15_Pt_out = c15_b_Pt_out;
  *chartInstance->c15_Tt_out = c15_b_Tt_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_GTF_EnginePath_TwoSpool
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c15_Cp(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
                     real_T c15_Ts, real_T c15_f)
{
  real_T c15_b_Cp;
  uint32_T c15_debug_family_var_map[7];
  real_T c15_Cp_p[9];
  real_T c15_SitaCp_p[8];
  real_T c15_nargin = 2.0;
  real_T c15_nargout = 1.0;
  int32_T c15_i0;
  static real_T c15_p[9] = { -0.081873, 0.797112, -3.234725, 7.097112, -8.893933,
    6.083152, -1.852148, 0.236688, 0.992313 };

  int32_T c15_i1;
  static real_T c15_b_p[8] = { -0.003919, -0.361112, 3.081778, -10.233795,
    17.254096, -15.863157, 8.347481, -0.718874 };

  real_T c15_A;
  real_T c15_x;
  real_T c15_b_x;
  real_T c15_c_x;
  real_T c15_y;
  real_T c15_d_x;
  real_T c15_b_y;
  int32_T c15_k;
  real_T c15_b_k;
  static real_T c15_dv0[9] = { -0.081873, 0.797112, -3.234725, 7.097112,
    -8.893933, 6.083152, -1.852148, 0.236688, 0.992313 };

  real_T c15_b_A;
  real_T c15_B;
  real_T c15_e_x;
  real_T c15_c_y;
  real_T c15_f_x;
  real_T c15_d_y;
  real_T c15_g_x;
  real_T c15_e_y;
  real_T c15_f_y;
  real_T c15_c_A;
  real_T c15_h_x;
  real_T c15_i_x;
  real_T c15_j_x;
  real_T c15_g_y;
  real_T c15_k_x;
  real_T c15_h_y;
  int32_T c15_c_k;
  real_T c15_d_k;
  static real_T c15_dv1[8] = { -0.003919, -0.361112, 3.081778, -10.233795,
    17.254096, -15.863157, 8.347481, -0.718874 };

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c15_b_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_Cp_p, 0U, c15_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_SitaCp_p, 1U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Ts, 4U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_f, 5U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Cp, 6U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c15_sfEvent, 2);
  for (c15_i0 = 0; c15_i0 < 9; c15_i0++) {
    c15_Cp_p[c15_i0] = c15_p[c15_i0];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c15_sfEvent, 3);
  for (c15_i1 = 0; c15_i1 < 8; c15_i1++) {
    c15_SitaCp_p[c15_i1] = c15_b_p[c15_i1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c15_sfEvent, 4);
  c15_A = c15_Ts;
  c15_x = c15_A;
  c15_b_x = c15_x;
  c15_c_x = c15_b_x;
  c15_y = c15_c_x / 1000.0;
  c15_d_x = c15_y;
  c15_b_y = -0.081873;
  for (c15_k = 0; c15_k < 8; c15_k++) {
    c15_b_k = 2.0 + (real_T)c15_k;
    c15_b_y = c15_d_x * c15_b_y + c15_dv0[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c15_b_k), 1, 9, 1, 0) - 1];
  }

  c15_b_A = c15_f;
  c15_B = 1.0 + c15_f;
  c15_e_x = c15_b_A;
  c15_c_y = c15_B;
  c15_f_x = c15_e_x;
  c15_d_y = c15_c_y;
  c15_g_x = c15_f_x;
  c15_e_y = c15_d_y;
  c15_f_y = c15_g_x / c15_e_y;
  c15_c_A = c15_Ts;
  c15_h_x = c15_c_A;
  c15_i_x = c15_h_x;
  c15_j_x = c15_i_x;
  c15_g_y = c15_j_x / 1000.0;
  c15_k_x = c15_g_y;
  c15_h_y = -0.003919;
  for (c15_c_k = 0; c15_c_k < 7; c15_c_k++) {
    c15_d_k = 2.0 + (real_T)c15_c_k;
    c15_h_y = c15_k_x * c15_h_y + c15_dv1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c15_d_k), 1, 8, 1, 0) - 1];
  }

  c15_b_Cp = (c15_b_y + c15_f_y * c15_h_y) * 1000.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c15_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  return c15_b_Cp;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c15_chartNumber, c15_instanceNumber, 0U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\k.m"));
  _SFD_SCRIPT_TRANSLATION(c15_chartNumber, c15_instanceNumber, 1U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\Cp.m"));
  _SFD_SCRIPT_TRANSLATION(c15_chartNumber, c15_instanceNumber, 2U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\R.m"));
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c15_b_Tt_out, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Tt_out),
    &c15_thisId);
  sf_mex_destroy(&c15_b_Tt_out);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_Tt_out;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_b_Tt_out = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Tt_out),
    &c15_thisId);
  sf_mex_destroy(&c15_b_Tt_out);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i2;
  real_T c15_b_inData[8];
  int32_T c15_i3;
  real_T c15_u[8];
  const mxArray *c15_y = NULL;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i2 = 0; c15_i2 < 8; c15_i2++) {
    c15_b_inData[c15_i2] = (*(real_T (*)[8])c15_inData)[c15_i2];
  }

  for (c15_i3 = 0; c15_i3 < 8; c15_i3++) {
    c15_u[c15_i3] = c15_b_inData[c15_i3];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 8), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i4;
  real_T c15_b_inData[9];
  int32_T c15_i5;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i4 = 0; c15_i4 < 9; c15_i4++) {
    c15_b_inData[c15_i4] = (*(real_T (*)[9])c15_inData)[c15_i4];
  }

  for (c15_i5 = 0; c15_i5 < 9; c15_i5++) {
    c15_u[c15_i5] = c15_b_inData[c15_i5];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

const mxArray *sf_c15_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 28, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  const mxArray *c15_rhs4 = NULL;
  const mxArray *c15_lhs4 = NULL;
  const mxArray *c15_rhs5 = NULL;
  const mxArray *c15_lhs5 = NULL;
  const mxArray *c15_rhs6 = NULL;
  const mxArray *c15_lhs6 = NULL;
  const mxArray *c15_rhs7 = NULL;
  const mxArray *c15_lhs7 = NULL;
  const mxArray *c15_rhs8 = NULL;
  const mxArray *c15_lhs8 = NULL;
  const mxArray *c15_rhs9 = NULL;
  const mxArray *c15_lhs9 = NULL;
  const mxArray *c15_rhs10 = NULL;
  const mxArray *c15_lhs10 = NULL;
  const mxArray *c15_rhs11 = NULL;
  const mxArray *c15_lhs11 = NULL;
  const mxArray *c15_rhs12 = NULL;
  const mxArray *c15_lhs12 = NULL;
  const mxArray *c15_rhs13 = NULL;
  const mxArray *c15_lhs13 = NULL;
  const mxArray *c15_rhs14 = NULL;
  const mxArray *c15_lhs14 = NULL;
  const mxArray *c15_rhs15 = NULL;
  const mxArray *c15_lhs15 = NULL;
  const mxArray *c15_rhs16 = NULL;
  const mxArray *c15_lhs16 = NULL;
  const mxArray *c15_rhs17 = NULL;
  const mxArray *c15_lhs17 = NULL;
  const mxArray *c15_rhs18 = NULL;
  const mxArray *c15_lhs18 = NULL;
  const mxArray *c15_rhs19 = NULL;
  const mxArray *c15_lhs19 = NULL;
  const mxArray *c15_rhs20 = NULL;
  const mxArray *c15_lhs20 = NULL;
  const mxArray *c15_rhs21 = NULL;
  const mxArray *c15_lhs21 = NULL;
  const mxArray *c15_rhs22 = NULL;
  const mxArray *c15_lhs22 = NULL;
  const mxArray *c15_rhs23 = NULL;
  const mxArray *c15_lhs23 = NULL;
  const mxArray *c15_rhs24 = NULL;
  const mxArray *c15_lhs24 = NULL;
  const mxArray *c15_rhs25 = NULL;
  const mxArray *c15_lhs25 = NULL;
  const mxArray *c15_rhs26 = NULL;
  const mxArray *c15_lhs26 = NULL;
  const mxArray *c15_rhs27 = NULL;
  const mxArray *c15_lhs27 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("k"), "name", "name", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/k.m"), "resolved", "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1430018432U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/k.m"), "context", "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("Cp"), "name", "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/Cp.m"), "resolved", "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1430030153U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/Cp.m"), "context", "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("rdivide"), "name", "name", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c15_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c15_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c15_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_div"), "name", "name", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c15_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c15_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/Cp.m"), "context", "context", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("polyval"), "name", "name", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1305296402U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c15_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c15_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c15_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/k.m"), "context", "context", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("R"), "name", "name", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/R.m"), "resolved", "resolved", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1432376608U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c15_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/k.m"), "context", "context", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c15_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mpower"), "name", "name", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c15_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c15_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("ismatrix"), "name", "name",
                  16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c15_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("power"), "name", "name", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395303306U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c15_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c15_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c15_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c15_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c15_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("floor"), "name", "name", 22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c15_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c15_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c15_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c15_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c15_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c15_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs27), "lhs", "lhs",
                  27);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
  sf_mex_destroy(&c15_rhs4);
  sf_mex_destroy(&c15_lhs4);
  sf_mex_destroy(&c15_rhs5);
  sf_mex_destroy(&c15_lhs5);
  sf_mex_destroy(&c15_rhs6);
  sf_mex_destroy(&c15_lhs6);
  sf_mex_destroy(&c15_rhs7);
  sf_mex_destroy(&c15_lhs7);
  sf_mex_destroy(&c15_rhs8);
  sf_mex_destroy(&c15_lhs8);
  sf_mex_destroy(&c15_rhs9);
  sf_mex_destroy(&c15_lhs9);
  sf_mex_destroy(&c15_rhs10);
  sf_mex_destroy(&c15_lhs10);
  sf_mex_destroy(&c15_rhs11);
  sf_mex_destroy(&c15_lhs11);
  sf_mex_destroy(&c15_rhs12);
  sf_mex_destroy(&c15_lhs12);
  sf_mex_destroy(&c15_rhs13);
  sf_mex_destroy(&c15_lhs13);
  sf_mex_destroy(&c15_rhs14);
  sf_mex_destroy(&c15_lhs14);
  sf_mex_destroy(&c15_rhs15);
  sf_mex_destroy(&c15_lhs15);
  sf_mex_destroy(&c15_rhs16);
  sf_mex_destroy(&c15_lhs16);
  sf_mex_destroy(&c15_rhs17);
  sf_mex_destroy(&c15_lhs17);
  sf_mex_destroy(&c15_rhs18);
  sf_mex_destroy(&c15_lhs18);
  sf_mex_destroy(&c15_rhs19);
  sf_mex_destroy(&c15_lhs19);
  sf_mex_destroy(&c15_rhs20);
  sf_mex_destroy(&c15_lhs20);
  sf_mex_destroy(&c15_rhs21);
  sf_mex_destroy(&c15_lhs21);
  sf_mex_destroy(&c15_rhs22);
  sf_mex_destroy(&c15_lhs22);
  sf_mex_destroy(&c15_rhs23);
  sf_mex_destroy(&c15_lhs23);
  sf_mex_destroy(&c15_rhs24);
  sf_mex_destroy(&c15_lhs24);
  sf_mex_destroy(&c15_rhs25);
  sf_mex_destroy(&c15_lhs25);
  sf_mex_destroy(&c15_rhs26);
  sf_mex_destroy(&c15_lhs26);
  sf_mex_destroy(&c15_rhs27);
  sf_mex_destroy(&c15_lhs27);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static real_T c15_mpower(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c15_a)
{
  real_T c15_b_a;
  real_T c15_c_a;
  real_T c15_ak;
  real_T c15_d_a;
  c15_b_a = c15_a;
  c15_c_a = c15_b_a;
  c15_eml_scalar_eg(chartInstance);
  c15_ak = c15_c_a;
  c15_d_a = c15_ak;
  c15_eml_scalar_eg(chartInstance);
  return c15_d_a * c15_d_a;
}

static void c15_eml_scalar_eg(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c15_eml_error(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  int32_T c15_i6;
  static char_T c15_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c15_u[31];
  const mxArray *c15_y = NULL;
  (void)chartInstance;
  for (c15_i6 = 0; c15_i6 < 31; c15_i6++) {
    c15_u[c15_i6] = c15_cv0[c15_i6];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_y));
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_c_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i7;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i7, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i7;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_d_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_b_is_active_c15_GTF_EnginePath_TwoSpool, const char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_GTF_EnginePath_TwoSpool), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_GTF_EnginePath_TwoSpool);
  return c15_y;
}

static uint8_T c15_e_emlrt_marshallIn
  (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  chartInstance->c15_T_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c15_P_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_Ma = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c15_Pt_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_Tt_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c15_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(317019770U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(854035244U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1195891772U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3250687665U);
}

mxArray* sf_c15_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
mxArray *sf_c15_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8ye2MZWnzKz9SVUznogUUF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c15_GTF_EnginePath_TwoSpool_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_GTF_EnginePath_TwoSpool_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_GTF_EnginePath_TwoSpool_jit_fallback_info(void)
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

mxArray *sf_c15_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_GTF_EnginePath_TwoSpool_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_GTF_EnginePath_TwoSpool(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Pt_out\",},{M[1],M[8],T\"Tt_out\",},{M[8],M[0],T\"is_active_c15_GTF_EnginePath_TwoSpool\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_GTF_EnginePath_TwoSpool_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GTF_EnginePath_TwoSpoolMachineNumber_,
           15,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"T_in");
          _SFD_SET_DATA_PROPS(1,1,1,0,"P_in");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Ma");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Pt_out");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Tt_out");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",8,-1,299);
        _SFD_CV_INIT_EML_IF(0,1,0,69,79,108,166);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,72,79,-1,3);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"k",0,-1,46);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"Cp",0,-1,273);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"R",0,-1,40);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c15_T_in);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c15_P_in);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c15_Ma);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c15_Pt_out);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c15_Tt_out);
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
  return "r18kPKExUx3KAHhD1j5spB";
}

static void sf_opaque_initialize_c15_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
  initialize_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  enable_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  disable_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  sf_gateway_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_GTF_EnginePath_TwoSpool
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_GTF_EnginePath_TwoSpool(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c15_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GTF_EnginePath_TwoSpool_optimization_info();
    }

    finalize_c15_GTF_EnginePath_TwoSpool
      ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_GTF_EnginePath_TwoSpool
    ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_GTF_EnginePath_TwoSpool(SimStruct *S)
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
    initialize_params_c15_GTF_EnginePath_TwoSpool
      ((SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GTF_EnginePath_TwoSpool_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3332300385U));
  ssSetChecksum1(S,(2140668931U));
  ssSetChecksum2(S,(2597555203U));
  ssSetChecksum3(S,(2435221437U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct *)utMalloc(sizeof
    (SFc15_GTF_EnginePath_TwoSpoolInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_GTF_EnginePath_TwoSpoolInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_GTF_EnginePath_TwoSpool;
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

void c15_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_GTF_EnginePath_TwoSpool(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_GTF_EnginePath_TwoSpool_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
