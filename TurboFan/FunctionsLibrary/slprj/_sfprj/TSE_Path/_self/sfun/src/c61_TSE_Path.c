/* Include files */

#include <stddef.h>
#include "blas.h"
#include "TSE_Path_sfun.h"
#include "c61_TSE_Path.h"
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
static const char * c61_debug_family_names[18] = { "WcoolGT2", "f", "fnew", "a",
  "b", "error", "h5newGuess", "Z", "nargin", "nargout", "WG5", "T5s", "WcoolGT",
  "T3s", "Wf", "T5snew", "WG5new", "h5new" };

static const char * c61_b_debug_family_names[9] = { "b_FuelAirRatio", "TE",
  "Hia", "Hif", "nargin", "nargout", "T", "FuelAirRatio", "Hi" };

/* Function Declarations */
static void initialize_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void initialize_params_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance);
static void enable_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void disable_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void c61_update_debugger_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance);
static void set_sim_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_st);
static void finalize_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void sf_gateway_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void mdl_start_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance);
static void c61_chartstep_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance);
static void initSimStructsc61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance);
static real_T c61_gashi(SFc61_TSE_PathInstanceStruct *chartInstance, real_T
  c61_T, real_T c61_FuelAirRatio);
static void init_script_number_translation(uint32_T c61_machineNumber, uint32_T
  c61_chartNumber, uint32_T c61_instanceNumber);
static const mxArray *c61_sf_marshallOut(void *chartInstanceVoid, void
  *c61_inData);
static real_T c61_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c61_b_h5new, const char_T *c61_identifier);
static real_T c61_b_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId);
static void c61_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c61_mxArrayInData, const char_T *c61_varName, void *c61_outData);
static void c61_info_helper(const mxArray **c61_info);
static const mxArray *c61_emlrt_marshallOut(const char * c61_u);
static const mxArray *c61_b_emlrt_marshallOut(const uint32_T c61_u);
static const mxArray *c61_b_sf_marshallOut(void *chartInstanceVoid, void
  *c61_inData);
static int32_T c61_c_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId);
static void c61_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c61_mxArrayInData, const char_T *c61_varName, void *c61_outData);
static uint8_T c61_d_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_b_is_active_c61_TSE_Path, const char_T
  *c61_identifier);
static uint8_T c61_e_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId);
static void init_dsm_address_info(SFc61_TSE_PathInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc61_TSE_PathInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c61_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c61_is_active_c61_TSE_Path = 0U;
}

static void initialize_params_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c61_update_debugger_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance)
{
  const mxArray *c61_st;
  const mxArray *c61_y = NULL;
  real_T c61_hoistedGlobal;
  real_T c61_u;
  const mxArray *c61_b_y = NULL;
  real_T c61_b_hoistedGlobal;
  real_T c61_b_u;
  const mxArray *c61_c_y = NULL;
  real_T c61_c_hoistedGlobal;
  real_T c61_c_u;
  const mxArray *c61_d_y = NULL;
  uint8_T c61_d_hoistedGlobal;
  uint8_T c61_d_u;
  const mxArray *c61_e_y = NULL;
  c61_st = NULL;
  c61_st = NULL;
  c61_y = NULL;
  sf_mex_assign(&c61_y, sf_mex_createcellmatrix(4, 1), false);
  c61_hoistedGlobal = *chartInstance->c61_T5snew;
  c61_u = c61_hoistedGlobal;
  c61_b_y = NULL;
  sf_mex_assign(&c61_b_y, sf_mex_create("y", &c61_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c61_y, 0, c61_b_y);
  c61_b_hoistedGlobal = *chartInstance->c61_WG5new;
  c61_b_u = c61_b_hoistedGlobal;
  c61_c_y = NULL;
  sf_mex_assign(&c61_c_y, sf_mex_create("y", &c61_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c61_y, 1, c61_c_y);
  c61_c_hoistedGlobal = *chartInstance->c61_h5new;
  c61_c_u = c61_c_hoistedGlobal;
  c61_d_y = NULL;
  sf_mex_assign(&c61_d_y, sf_mex_create("y", &c61_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c61_y, 2, c61_d_y);
  c61_d_hoistedGlobal = chartInstance->c61_is_active_c61_TSE_Path;
  c61_d_u = c61_d_hoistedGlobal;
  c61_e_y = NULL;
  sf_mex_assign(&c61_e_y, sf_mex_create("y", &c61_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c61_y, 3, c61_e_y);
  sf_mex_assign(&c61_st, c61_y, false);
  return c61_st;
}

static void set_sim_state_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_st)
{
  const mxArray *c61_u;
  chartInstance->c61_doneDoubleBufferReInit = true;
  c61_u = sf_mex_dup(c61_st);
  *chartInstance->c61_T5snew = c61_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c61_u, 0)), "T5snew");
  *chartInstance->c61_WG5new = c61_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c61_u, 1)), "WG5new");
  *chartInstance->c61_h5new = c61_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c61_u, 2)), "h5new");
  chartInstance->c61_is_active_c61_TSE_Path = c61_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c61_u, 3)),
     "is_active_c61_TSE_Path");
  sf_mex_destroy(&c61_u);
  c61_update_debugger_state_c61_TSE_Path(chartInstance);
  sf_mex_destroy(&c61_st);
}

static void finalize_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c61_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_WG5, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_T5s, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_WcoolGT, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_T3s, 3U);
  chartInstance->c61_sfEvent = CALL_EVENT;
  c61_chartstep_c61_TSE_Path(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_TSE_PathMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_T5snew, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_Wf, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_WG5new, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c61_h5new, 7U);
}

static void mdl_start_c61_TSE_Path(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c61_chartstep_c61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance)
{
  real_T c61_hoistedGlobal;
  real_T c61_b_hoistedGlobal;
  real_T c61_c_hoistedGlobal;
  real_T c61_d_hoistedGlobal;
  real_T c61_e_hoistedGlobal;
  real_T c61_b_WG5;
  real_T c61_b_T5s;
  real_T c61_b_WcoolGT;
  real_T c61_b_T3s;
  real_T c61_b_Wf;
  uint32_T c61_debug_family_var_map[18];
  real_T c61_WcoolGT2;
  real_T c61_f;
  real_T c61_fnew;
  real_T c61_a;
  real_T c61_b;
  real_T c61_error;
  real_T c61_h5newGuess;
  real_T c61_Z;
  real_T c61_nargin = 5.0;
  real_T c61_nargout = 3.0;
  real_T c61_b_T5snew;
  real_T c61_b_WG5new;
  real_T c61_b_h5new;
  real_T c61_A;
  real_T c61_B;
  real_T c61_x;
  real_T c61_y;
  real_T c61_b_x;
  real_T c61_b_y;
  real_T c61_c_x;
  real_T c61_c_y;
  real_T c61_b_A;
  real_T c61_b_B;
  real_T c61_d_x;
  real_T c61_d_y;
  real_T c61_e_x;
  real_T c61_e_y;
  real_T c61_f_x;
  real_T c61_f_y;
  real_T c61_c_A;
  real_T c61_c_B;
  real_T c61_g_x;
  real_T c61_g_y;
  real_T c61_h_x;
  real_T c61_h_y;
  real_T c61_i_x;
  real_T c61_i_y;
  real_T c61_d_A;
  real_T c61_j_x;
  real_T c61_k_x;
  real_T c61_l_x;
  real_T c61_j_y;
  real_T c61_e_A;
  real_T c61_d_B;
  real_T c61_m_x;
  real_T c61_k_y;
  real_T c61_n_x;
  real_T c61_l_y;
  real_T c61_o_x;
  real_T c61_m_y;
  real_T c61_n_y;
  real_T c61_p_x;
  real_T c61_q_x;
  real_T c61_f_A;
  real_T c61_r_x;
  real_T c61_s_x;
  real_T c61_t_x;
  real_T c61_g_A;
  real_T c61_u_x;
  real_T c61_v_x;
  real_T c61_w_x;
  real_T c61_h_A;
  real_T c61_x_x;
  real_T c61_y_x;
  real_T c61_ab_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c61_sfEvent);
  c61_hoistedGlobal = *chartInstance->c61_WG5;
  c61_b_hoistedGlobal = *chartInstance->c61_T5s;
  c61_c_hoistedGlobal = *chartInstance->c61_WcoolGT;
  c61_d_hoistedGlobal = *chartInstance->c61_T3s;
  c61_e_hoistedGlobal = *chartInstance->c61_Wf;
  c61_b_WG5 = c61_hoistedGlobal;
  c61_b_T5s = c61_b_hoistedGlobal;
  c61_b_WcoolGT = c61_c_hoistedGlobal;
  c61_b_T3s = c61_d_hoistedGlobal;
  c61_b_Wf = c61_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c61_debug_family_names,
    c61_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_WcoolGT2, 0U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_f, 1U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_fnew, 2U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_a, 3U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_b, 4U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_error, 5U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_h5newGuess, 6U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_Z, 7U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_nargin, 8U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_nargout, 9U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c61_b_WG5, 10U, c61_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c61_b_T5s, 11U, c61_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c61_b_WcoolGT, 12U, c61_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c61_b_T3s, 13U, c61_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c61_b_Wf, 14U, c61_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_b_T5snew, 15U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_b_WG5new, 16U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_b_h5new, 17U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 2);
  c61_WcoolGT2 = c61_b_WcoolGT * 0.17;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 3);
  c61_A = c61_b_Wf;
  c61_B = c61_b_WG5 - c61_b_Wf;
  c61_x = c61_A;
  c61_y = c61_B;
  c61_b_x = c61_x;
  c61_b_y = c61_y;
  c61_c_x = c61_b_x;
  c61_c_y = c61_b_y;
  c61_f = c61_c_x / c61_c_y;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 4);
  c61_b_A = c61_b_Wf;
  c61_b_B = (c61_b_WG5 + c61_WcoolGT2) - c61_b_Wf;
  c61_d_x = c61_b_A;
  c61_d_y = c61_b_B;
  c61_e_x = c61_d_x;
  c61_e_y = c61_d_y;
  c61_f_x = c61_e_x;
  c61_f_y = c61_e_y;
  c61_fnew = c61_f_x / c61_f_y;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 5);
  c61_c_A = c61_b_WG5 * c61_gashi(chartInstance, c61_b_T5s, c61_f) +
    c61_WcoolGT2 * c61_gashi(chartInstance, c61_b_T3s, 0.0);
  c61_c_B = c61_b_WG5 + c61_WcoolGT2;
  c61_g_x = c61_c_A;
  c61_g_y = c61_c_B;
  c61_h_x = c61_g_x;
  c61_h_y = c61_g_y;
  c61_i_x = c61_h_x;
  c61_i_y = c61_h_y;
  c61_b_h5new = c61_i_x / c61_i_y;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 6);
  c61_b_WG5new = c61_b_WG5 + c61_WcoolGT2;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 7);
  c61_a = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 8);
  c61_b = 5000.0;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 9);
  c61_error = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 10);
  while (CV_EML_WHILE(0, 1, 0, c61_error > 1.0E-9)) {
    _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 11);
    c61_d_A = c61_a + c61_b;
    c61_j_x = c61_d_A;
    c61_k_x = c61_j_x;
    c61_l_x = c61_k_x;
    c61_j_y = c61_l_x / 2.0;
    c61_h5newGuess = c61_gashi(chartInstance, c61_j_y, c61_fnew);
    _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 12);
    c61_e_A = c61_h5newGuess - c61_b_h5new;
    c61_d_B = c61_b_h5new;
    c61_m_x = c61_e_A;
    c61_k_y = c61_d_B;
    c61_n_x = c61_m_x;
    c61_l_y = c61_k_y;
    c61_o_x = c61_n_x;
    c61_m_y = c61_l_y;
    c61_n_y = c61_o_x / c61_m_y;
    c61_p_x = c61_n_y;
    c61_q_x = c61_p_x;
    c61_error = muDoubleScalarAbs(c61_q_x);
    _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 13);
    c61_Z = c61_h5newGuess - c61_b_h5new;
    _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 14);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c61_Z, 0.0, -1, 4U,
          c61_Z > 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 15);
      c61_f_A = c61_a + c61_b;
      c61_r_x = c61_f_A;
      c61_s_x = c61_r_x;
      c61_t_x = c61_s_x;
      c61_b = c61_t_x / 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 17);
      c61_g_A = c61_a + c61_b;
      c61_u_x = c61_g_A;
      c61_v_x = c61_u_x;
      c61_w_x = c61_v_x;
      c61_a = c61_w_x / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 10);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, 20);
  c61_h_A = c61_a + c61_b;
  c61_x_x = c61_h_A;
  c61_y_x = c61_x_x;
  c61_ab_x = c61_y_x;
  c61_b_T5snew = c61_ab_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c61_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c61_T5snew = c61_b_T5snew;
  *chartInstance->c61_WG5new = c61_b_WG5new;
  *chartInstance->c61_h5new = c61_b_h5new;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c61_sfEvent);
}

static void initSimStructsc61_TSE_Path(SFc61_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c61_gashi(SFc61_TSE_PathInstanceStruct *chartInstance, real_T
  c61_T, real_T c61_FuelAirRatio)
{
  real_T c61_Hi;
  uint32_T c61_debug_family_var_map[9];
  real_T c61_b_FuelAirRatio;
  real_T c61_TE;
  real_T c61_Hia;
  real_T c61_Hif;
  real_T c61_nargin = 2.0;
  real_T c61_nargout = 1.0;
  real_T c61_A;
  real_T c61_x;
  real_T c61_b_x;
  real_T c61_c_x;
  real_T c61_b_A;
  real_T c61_d_x;
  real_T c61_e_x;
  real_T c61_f_x;
  real_T c61_c_A;
  real_T c61_B;
  real_T c61_g_x;
  real_T c61_y;
  real_T c61_h_x;
  real_T c61_b_y;
  real_T c61_i_x;
  real_T c61_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c61_b_debug_family_names,
    c61_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_b_FuelAirRatio, 0U,
    c61_sf_marshallOut, c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_TE, 1U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_Hia, 2U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_Hif, 3U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_nargin, 4U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_nargout, 5U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_T, 6U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_FuelAirRatio, 7U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c61_Hi, 8U, c61_sf_marshallOut,
    c61_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 6);
  if (CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c61_FuelAirRatio, 0.0,
        -1, 2U, c61_FuelAirRatio < 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 7);
    c61_FuelAirRatio = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 10);
  if (CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c61_FuelAirRatio,
        0.067623, -1, 4U, c61_FuelAirRatio > 0.067623))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 11);
    c61_FuelAirRatio = 0.067623;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 14);
  c61_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 16);
  if (CV_SCRIPT_IF(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c61_FuelAirRatio, 0.0,
        -1, 0U, c61_FuelAirRatio == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 17);
    c61_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 21);
  c61_A = c61_T * 9.0;
  c61_x = c61_A;
  c61_b_x = c61_x;
  c61_c_x = c61_b_x;
  c61_TE = c61_c_x / 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 22);
  if (CV_SCRIPT_IF(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c61_TE, 300.0, -1, 2U,
        c61_TE < 300.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 23);
    c61_TE = 300.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 26);
  if (CV_SCRIPT_IF(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c61_TE, 4000.0, -1, 4U,
        c61_TE > 4000.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 27);
    c61_TE = 4000.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 31);
  c61_Hia = (((((((1.2644425E-26 * c61_TE - 2.0752522E-22) * c61_TE +
                  1.270263E-18) * c61_TE - 3.0256518E-15) * c61_TE -
                1.6794594E-12) * c61_TE + 2.1839826E-8) * c61_TE - 2.576844E-5) *
             c61_TE + 0.25020051) * c61_TE - 1.7558886;
  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 33);
  switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c61_b_FuelAirRatio)) {
   case 1:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 38);
    c61_Hi = c61_Hia * 2.3254259;
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 42);
    c61_Hif = (((((((9.0848388E-26 * c61_TE - 1.9050949E-21) * c61_TE +
                    1.7021525E-17) * c61_TE - 8.4102208E-14) * c61_TE +
                  2.4921698E-10) * c61_TE - 4.5906332E-7) * c61_TE +
                0.0006129315) * c61_TE + 0.073816638) * c61_TE + 30.58153;
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 43);
    c61_c_A = c61_Hia + c61_FuelAirRatio * c61_Hif;
    c61_B = 1.0 + c61_FuelAirRatio;
    c61_g_x = c61_c_A;
    c61_y = c61_B;
    c61_h_x = c61_g_x;
    c61_b_y = c61_y;
    c61_i_x = c61_h_x;
    c61_c_y = c61_b_y;
    c61_Hif = c61_i_x / c61_c_y;
    _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 46);
    c61_Hi = c61_Hif * 2.3254259;
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, 48);
  c61_b_A = c61_TE * 5.0;
  c61_d_x = c61_b_A;
  c61_e_x = c61_d_x;
  c61_f_x = c61_e_x;
  c61_T = c61_f_x / 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c61_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  return c61_Hi;
}

static void init_script_number_translation(uint32_T c61_machineNumber, uint32_T
  c61_chartNumber, uint32_T c61_instanceNumber)
{
  (void)c61_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c61_chartNumber, c61_instanceNumber, 0U,
    sf_debug_get_script_id(
    "I:\\MATLABWORK\\GTFEngine\\FunctionsLibrary\\gashi.m"));
}

static const mxArray *c61_sf_marshallOut(void *chartInstanceVoid, void
  *c61_inData)
{
  const mxArray *c61_mxArrayOutData = NULL;
  real_T c61_u;
  const mxArray *c61_y = NULL;
  SFc61_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc61_TSE_PathInstanceStruct *)chartInstanceVoid;
  c61_mxArrayOutData = NULL;
  c61_u = *(real_T *)c61_inData;
  c61_y = NULL;
  sf_mex_assign(&c61_y, sf_mex_create("y", &c61_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c61_mxArrayOutData, c61_y, false);
  return c61_mxArrayOutData;
}

static real_T c61_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c61_b_h5new, const char_T *c61_identifier)
{
  real_T c61_y;
  emlrtMsgIdentifier c61_thisId;
  c61_thisId.fIdentifier = c61_identifier;
  c61_thisId.fParent = NULL;
  c61_y = c61_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c61_b_h5new),
    &c61_thisId);
  sf_mex_destroy(&c61_b_h5new);
  return c61_y;
}

static real_T c61_b_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId)
{
  real_T c61_y;
  real_T c61_d0;
  (void)chartInstance;
  sf_mex_import(c61_parentId, sf_mex_dup(c61_u), &c61_d0, 1, 0, 0U, 0, 0U, 0);
  c61_y = c61_d0;
  sf_mex_destroy(&c61_u);
  return c61_y;
}

static void c61_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c61_mxArrayInData, const char_T *c61_varName, void *c61_outData)
{
  const mxArray *c61_b_h5new;
  const char_T *c61_identifier;
  emlrtMsgIdentifier c61_thisId;
  real_T c61_y;
  SFc61_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc61_TSE_PathInstanceStruct *)chartInstanceVoid;
  c61_b_h5new = sf_mex_dup(c61_mxArrayInData);
  c61_identifier = c61_varName;
  c61_thisId.fIdentifier = c61_identifier;
  c61_thisId.fParent = NULL;
  c61_y = c61_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c61_b_h5new),
    &c61_thisId);
  sf_mex_destroy(&c61_b_h5new);
  *(real_T *)c61_outData = c61_y;
  sf_mex_destroy(&c61_mxArrayInData);
}

const mxArray *sf_c61_TSE_Path_get_eml_resolved_functions_info(void)
{
  const mxArray *c61_nameCaptureInfo = NULL;
  c61_nameCaptureInfo = NULL;
  sf_mex_assign(&c61_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c61_info_helper(&c61_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c61_nameCaptureInfo);
  return c61_nameCaptureInfo;
}

static void c61_info_helper(const mxArray **c61_info)
{
  const mxArray *c61_rhs0 = NULL;
  const mxArray *c61_lhs0 = NULL;
  const mxArray *c61_rhs1 = NULL;
  const mxArray *c61_lhs1 = NULL;
  const mxArray *c61_rhs2 = NULL;
  const mxArray *c61_lhs2 = NULL;
  const mxArray *c61_rhs3 = NULL;
  const mxArray *c61_lhs3 = NULL;
  const mxArray *c61_rhs4 = NULL;
  const mxArray *c61_lhs4 = NULL;
  const mxArray *c61_rhs5 = NULL;
  const mxArray *c61_lhs5 = NULL;
  const mxArray *c61_rhs6 = NULL;
  const mxArray *c61_lhs6 = NULL;
  const mxArray *c61_rhs7 = NULL;
  const mxArray *c61_lhs7 = NULL;
  const mxArray *c61_rhs8 = NULL;
  const mxArray *c61_lhs8 = NULL;
  const mxArray *c61_rhs9 = NULL;
  const mxArray *c61_lhs9 = NULL;
  const mxArray *c61_rhs10 = NULL;
  const mxArray *c61_lhs10 = NULL;
  const mxArray *c61_rhs11 = NULL;
  const mxArray *c61_lhs11 = NULL;
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c61_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c61_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c61_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c61_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c61_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c61_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c61_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("gashi"), "name", "name", 7);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1428734872U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c61_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "context", "context",
                  8);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("mrdivide"), "name", "name",
                  8);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c61_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("abs"), "name", "name", 9);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c61_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c61_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 11);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c61_info, c61_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c61_info, c61_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c61_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c61_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c61_info, sf_mex_duplicatearraysafe(&c61_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c61_rhs0);
  sf_mex_destroy(&c61_lhs0);
  sf_mex_destroy(&c61_rhs1);
  sf_mex_destroy(&c61_lhs1);
  sf_mex_destroy(&c61_rhs2);
  sf_mex_destroy(&c61_lhs2);
  sf_mex_destroy(&c61_rhs3);
  sf_mex_destroy(&c61_lhs3);
  sf_mex_destroy(&c61_rhs4);
  sf_mex_destroy(&c61_lhs4);
  sf_mex_destroy(&c61_rhs5);
  sf_mex_destroy(&c61_lhs5);
  sf_mex_destroy(&c61_rhs6);
  sf_mex_destroy(&c61_lhs6);
  sf_mex_destroy(&c61_rhs7);
  sf_mex_destroy(&c61_lhs7);
  sf_mex_destroy(&c61_rhs8);
  sf_mex_destroy(&c61_lhs8);
  sf_mex_destroy(&c61_rhs9);
  sf_mex_destroy(&c61_lhs9);
  sf_mex_destroy(&c61_rhs10);
  sf_mex_destroy(&c61_lhs10);
  sf_mex_destroy(&c61_rhs11);
  sf_mex_destroy(&c61_lhs11);
}

static const mxArray *c61_emlrt_marshallOut(const char * c61_u)
{
  const mxArray *c61_y = NULL;
  c61_y = NULL;
  sf_mex_assign(&c61_y, sf_mex_create("y", c61_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c61_u)), false);
  return c61_y;
}

static const mxArray *c61_b_emlrt_marshallOut(const uint32_T c61_u)
{
  const mxArray *c61_y = NULL;
  c61_y = NULL;
  sf_mex_assign(&c61_y, sf_mex_create("y", &c61_u, 7, 0U, 0U, 0U, 0), false);
  return c61_y;
}

static const mxArray *c61_b_sf_marshallOut(void *chartInstanceVoid, void
  *c61_inData)
{
  const mxArray *c61_mxArrayOutData = NULL;
  int32_T c61_u;
  const mxArray *c61_y = NULL;
  SFc61_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc61_TSE_PathInstanceStruct *)chartInstanceVoid;
  c61_mxArrayOutData = NULL;
  c61_u = *(int32_T *)c61_inData;
  c61_y = NULL;
  sf_mex_assign(&c61_y, sf_mex_create("y", &c61_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c61_mxArrayOutData, c61_y, false);
  return c61_mxArrayOutData;
}

static int32_T c61_c_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId)
{
  int32_T c61_y;
  int32_T c61_i0;
  (void)chartInstance;
  sf_mex_import(c61_parentId, sf_mex_dup(c61_u), &c61_i0, 1, 6, 0U, 0, 0U, 0);
  c61_y = c61_i0;
  sf_mex_destroy(&c61_u);
  return c61_y;
}

static void c61_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c61_mxArrayInData, const char_T *c61_varName, void *c61_outData)
{
  const mxArray *c61_b_sfEvent;
  const char_T *c61_identifier;
  emlrtMsgIdentifier c61_thisId;
  int32_T c61_y;
  SFc61_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc61_TSE_PathInstanceStruct *)chartInstanceVoid;
  c61_b_sfEvent = sf_mex_dup(c61_mxArrayInData);
  c61_identifier = c61_varName;
  c61_thisId.fIdentifier = c61_identifier;
  c61_thisId.fParent = NULL;
  c61_y = c61_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c61_b_sfEvent),
    &c61_thisId);
  sf_mex_destroy(&c61_b_sfEvent);
  *(int32_T *)c61_outData = c61_y;
  sf_mex_destroy(&c61_mxArrayInData);
}

static uint8_T c61_d_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_b_is_active_c61_TSE_Path, const char_T
  *c61_identifier)
{
  uint8_T c61_y;
  emlrtMsgIdentifier c61_thisId;
  c61_thisId.fIdentifier = c61_identifier;
  c61_thisId.fParent = NULL;
  c61_y = c61_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c61_b_is_active_c61_TSE_Path), &c61_thisId);
  sf_mex_destroy(&c61_b_is_active_c61_TSE_Path);
  return c61_y;
}

static uint8_T c61_e_emlrt_marshallIn(SFc61_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c61_u, const emlrtMsgIdentifier *c61_parentId)
{
  uint8_T c61_y;
  uint8_T c61_u0;
  (void)chartInstance;
  sf_mex_import(c61_parentId, sf_mex_dup(c61_u), &c61_u0, 1, 3, 0U, 0, 0U, 0);
  c61_y = c61_u0;
  sf_mex_destroy(&c61_u);
  return c61_y;
}

static void init_dsm_address_info(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc61_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c61_WG5 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c61_T5s = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c61_WcoolGT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c61_T3s = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c61_T5snew = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c61_Wf = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c61_WG5new = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c61_h5new = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c61_TSE_Path_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1168413646U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2521074264U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3039066509U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3394269032U);
}

mxArray* sf_c61_TSE_Path_get_post_codegen_info(void);
mxArray *sf_c61_TSE_Path_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WcEdgJ4jcUBjZhkySBtuwG");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c61_TSE_Path_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c61_TSE_Path_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c61_TSE_Path_jit_fallback_info(void)
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

mxArray *sf_c61_TSE_Path_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c61_TSE_Path_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c61_TSE_Path(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"T5snew\",},{M[1],M[10],T\"WG5new\",},{M[1],M[11],T\"h5new\",},{M[8],M[0],T\"is_active_c61_TSE_Path\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c61_TSE_Path_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc61_TSE_PathInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc61_TSE_PathInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _TSE_PathMachineNumber_,
           61,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"WG5");
          _SFD_SET_DATA_PROPS(1,1,1,0,"T5s");
          _SFD_SET_DATA_PROPS(2,1,1,0,"WcoolGT");
          _SFD_SET_DATA_PROPS(3,1,1,0,"T3s");
          _SFD_SET_DATA_PROPS(4,2,0,1,"T5snew");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Wf");
          _SFD_SET_DATA_PROPS(6,2,0,1,"WG5new");
          _SFD_SET_DATA_PROPS(7,2,0,1,"h5new");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,441);
        _SFD_CV_INIT_EML_IF(0,1,0,353,359,383,414);
        _SFD_CV_INIT_EML_WHILE(0,1,0,231,248,418);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,356,359,-1,4);
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
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)c61_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)c61_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c61_sf_marshallOut,(MexInFcnForType)c61_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c61_WG5);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c61_T5s);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c61_WcoolGT);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c61_T3s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c61_T5snew);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c61_Wf);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c61_WG5new);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c61_h5new);
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
  return "jbOjt0XXNdx2cZujOSqImC";
}

static void sf_opaque_initialize_c61_TSE_Path(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc61_TSE_PathInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*)
    chartInstanceVar);
  initialize_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c61_TSE_Path(void *chartInstanceVar)
{
  enable_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c61_TSE_Path(void *chartInstanceVar)
{
  disable_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c61_TSE_Path(void *chartInstanceVar)
{
  sf_gateway_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c61_TSE_Path(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c61_TSE_Path(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c61_TSE_Path(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc61_TSE_PathInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_TSE_Path_optimization_info();
    }

    finalize_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc61_TSE_Path((SFc61_TSE_PathInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c61_TSE_Path(SimStruct *S)
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
    initialize_params_c61_TSE_Path((SFc61_TSE_PathInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c61_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_TSE_Path_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      61);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,61,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,61,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,61);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,61,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,61,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,61);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2063206904U));
  ssSetChecksum1(S,(1720659632U));
  ssSetChecksum2(S,(3856887169U));
  ssSetChecksum3(S,(3521393111U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c61_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c61_TSE_Path(SimStruct *S)
{
  SFc61_TSE_PathInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc61_TSE_PathInstanceStruct *)utMalloc(sizeof
    (SFc61_TSE_PathInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc61_TSE_PathInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c61_TSE_Path;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c61_TSE_Path;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c61_TSE_Path;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c61_TSE_Path;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c61_TSE_Path;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c61_TSE_Path;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c61_TSE_Path;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c61_TSE_Path;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c61_TSE_Path;
  chartInstance->chartInfo.mdlStart = mdlStart_c61_TSE_Path;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c61_TSE_Path;
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

void c61_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c61_TSE_Path(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c61_TSE_Path(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c61_TSE_Path(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c61_TSE_Path_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
