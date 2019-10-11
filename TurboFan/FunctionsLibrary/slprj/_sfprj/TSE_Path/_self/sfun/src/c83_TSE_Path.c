/* Include files */

#include <stddef.h>
#include "blas.h"
#include "TSE_Path_sfun.h"
#include "c83_TSE_Path.h"
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
static const char * c83_debug_family_names[18] = { "WcoolPT2", "fnew", "a", "b",
  "error", "h6newGuess", "Z", "nargin", "nargout", "WG6", "T6s", "WcoolPT",
  "T3s", "Wf", "T6snew", "WG6new", "h6new", "f" };

static const char * c83_b_debug_family_names[9] = { "b_FuelAirRatio", "TE",
  "Hia", "Hif", "nargin", "nargout", "T", "FuelAirRatio", "Hi" };

/* Function Declarations */
static void initialize_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void initialize_params_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance);
static void enable_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void disable_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void c83_update_debugger_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance);
static void set_sim_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_st);
static void finalize_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void sf_gateway_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void mdl_start_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance);
static void c83_chartstep_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance);
static void initSimStructsc83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance);
static real_T c83_gashi(SFc83_TSE_PathInstanceStruct *chartInstance, real_T
  c83_T, real_T c83_FuelAirRatio);
static void init_script_number_translation(uint32_T c83_machineNumber, uint32_T
  c83_chartNumber, uint32_T c83_instanceNumber);
static const mxArray *c83_sf_marshallOut(void *chartInstanceVoid, void
  *c83_inData);
static real_T c83_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c83_b_f, const char_T *c83_identifier);
static real_T c83_b_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId);
static void c83_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c83_mxArrayInData, const char_T *c83_varName, void *c83_outData);
static void c83_info_helper(const mxArray **c83_info);
static const mxArray *c83_emlrt_marshallOut(const char * c83_u);
static const mxArray *c83_b_emlrt_marshallOut(const uint32_T c83_u);
static const mxArray *c83_b_sf_marshallOut(void *chartInstanceVoid, void
  *c83_inData);
static int32_T c83_c_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId);
static void c83_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c83_mxArrayInData, const char_T *c83_varName, void *c83_outData);
static uint8_T c83_d_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_b_is_active_c83_TSE_Path, const char_T
  *c83_identifier);
static uint8_T c83_e_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId);
static void init_dsm_address_info(SFc83_TSE_PathInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc83_TSE_PathInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c83_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c83_is_active_c83_TSE_Path = 0U;
}

static void initialize_params_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c83_update_debugger_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance)
{
  const mxArray *c83_st;
  const mxArray *c83_y = NULL;
  real_T c83_hoistedGlobal;
  real_T c83_u;
  const mxArray *c83_b_y = NULL;
  real_T c83_b_hoistedGlobal;
  real_T c83_b_u;
  const mxArray *c83_c_y = NULL;
  real_T c83_c_hoistedGlobal;
  real_T c83_c_u;
  const mxArray *c83_d_y = NULL;
  real_T c83_d_hoistedGlobal;
  real_T c83_d_u;
  const mxArray *c83_e_y = NULL;
  uint8_T c83_e_hoistedGlobal;
  uint8_T c83_e_u;
  const mxArray *c83_f_y = NULL;
  c83_st = NULL;
  c83_st = NULL;
  c83_y = NULL;
  sf_mex_assign(&c83_y, sf_mex_createcellmatrix(5, 1), false);
  c83_hoistedGlobal = *chartInstance->c83_T6snew;
  c83_u = c83_hoistedGlobal;
  c83_b_y = NULL;
  sf_mex_assign(&c83_b_y, sf_mex_create("y", &c83_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c83_y, 0, c83_b_y);
  c83_b_hoistedGlobal = *chartInstance->c83_WG6new;
  c83_b_u = c83_b_hoistedGlobal;
  c83_c_y = NULL;
  sf_mex_assign(&c83_c_y, sf_mex_create("y", &c83_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c83_y, 1, c83_c_y);
  c83_c_hoistedGlobal = *chartInstance->c83_f;
  c83_c_u = c83_c_hoistedGlobal;
  c83_d_y = NULL;
  sf_mex_assign(&c83_d_y, sf_mex_create("y", &c83_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c83_y, 2, c83_d_y);
  c83_d_hoistedGlobal = *chartInstance->c83_h6new;
  c83_d_u = c83_d_hoistedGlobal;
  c83_e_y = NULL;
  sf_mex_assign(&c83_e_y, sf_mex_create("y", &c83_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c83_y, 3, c83_e_y);
  c83_e_hoistedGlobal = chartInstance->c83_is_active_c83_TSE_Path;
  c83_e_u = c83_e_hoistedGlobal;
  c83_f_y = NULL;
  sf_mex_assign(&c83_f_y, sf_mex_create("y", &c83_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c83_y, 4, c83_f_y);
  sf_mex_assign(&c83_st, c83_y, false);
  return c83_st;
}

static void set_sim_state_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_st)
{
  const mxArray *c83_u;
  chartInstance->c83_doneDoubleBufferReInit = true;
  c83_u = sf_mex_dup(c83_st);
  *chartInstance->c83_T6snew = c83_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c83_u, 0)), "T6snew");
  *chartInstance->c83_WG6new = c83_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c83_u, 1)), "WG6new");
  *chartInstance->c83_f = c83_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c83_u, 2)), "f");
  *chartInstance->c83_h6new = c83_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c83_u, 3)), "h6new");
  chartInstance->c83_is_active_c83_TSE_Path = c83_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c83_u, 4)),
     "is_active_c83_TSE_Path");
  sf_mex_destroy(&c83_u);
  c83_update_debugger_state_c83_TSE_Path(chartInstance);
  sf_mex_destroy(&c83_st);
}

static void finalize_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c83_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_WG6, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_T6s, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_WcoolPT, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_T3s, 3U);
  chartInstance->c83_sfEvent = CALL_EVENT;
  c83_chartstep_c83_TSE_Path(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_TSE_PathMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_T6snew, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_Wf, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_WG6new, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_h6new, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c83_f, 8U);
}

static void mdl_start_c83_TSE_Path(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c83_chartstep_c83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance)
{
  real_T c83_hoistedGlobal;
  real_T c83_b_hoistedGlobal;
  real_T c83_c_hoistedGlobal;
  real_T c83_d_hoistedGlobal;
  real_T c83_e_hoistedGlobal;
  real_T c83_b_WG6;
  real_T c83_b_T6s;
  real_T c83_b_WcoolPT;
  real_T c83_b_T3s;
  real_T c83_b_Wf;
  uint32_T c83_debug_family_var_map[18];
  real_T c83_WcoolPT2;
  real_T c83_fnew;
  real_T c83_a;
  real_T c83_b;
  real_T c83_error;
  real_T c83_h6newGuess;
  real_T c83_Z;
  real_T c83_nargin = 5.0;
  real_T c83_nargout = 4.0;
  real_T c83_b_T6snew;
  real_T c83_b_WG6new;
  real_T c83_b_h6new;
  real_T c83_b_f;
  real_T c83_A;
  real_T c83_B;
  real_T c83_x;
  real_T c83_y;
  real_T c83_b_x;
  real_T c83_b_y;
  real_T c83_c_x;
  real_T c83_c_y;
  real_T c83_b_A;
  real_T c83_b_B;
  real_T c83_d_x;
  real_T c83_d_y;
  real_T c83_e_x;
  real_T c83_e_y;
  real_T c83_f_x;
  real_T c83_f_y;
  real_T c83_c_A;
  real_T c83_c_B;
  real_T c83_g_x;
  real_T c83_g_y;
  real_T c83_h_x;
  real_T c83_h_y;
  real_T c83_i_x;
  real_T c83_i_y;
  real_T c83_d_A;
  real_T c83_j_x;
  real_T c83_k_x;
  real_T c83_l_x;
  real_T c83_j_y;
  real_T c83_e_A;
  real_T c83_d_B;
  real_T c83_m_x;
  real_T c83_k_y;
  real_T c83_n_x;
  real_T c83_l_y;
  real_T c83_o_x;
  real_T c83_m_y;
  real_T c83_n_y;
  real_T c83_p_x;
  real_T c83_q_x;
  real_T c83_f_A;
  real_T c83_r_x;
  real_T c83_s_x;
  real_T c83_t_x;
  real_T c83_g_A;
  real_T c83_u_x;
  real_T c83_v_x;
  real_T c83_w_x;
  real_T c83_h_A;
  real_T c83_x_x;
  real_T c83_y_x;
  real_T c83_ab_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c83_sfEvent);
  c83_hoistedGlobal = *chartInstance->c83_WG6;
  c83_b_hoistedGlobal = *chartInstance->c83_T6s;
  c83_c_hoistedGlobal = *chartInstance->c83_WcoolPT;
  c83_d_hoistedGlobal = *chartInstance->c83_T3s;
  c83_e_hoistedGlobal = *chartInstance->c83_Wf;
  c83_b_WG6 = c83_hoistedGlobal;
  c83_b_T6s = c83_b_hoistedGlobal;
  c83_b_WcoolPT = c83_c_hoistedGlobal;
  c83_b_T3s = c83_d_hoistedGlobal;
  c83_b_Wf = c83_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c83_debug_family_names,
    c83_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_WcoolPT2, 0U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_fnew, 1U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_a, 2U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b, 3U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_error, 4U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_h6newGuess, 5U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_Z, 6U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_nargin, 7U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_nargout, 8U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c83_b_WG6, 9U, c83_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c83_b_T6s, 10U, c83_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c83_b_WcoolPT, 11U, c83_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c83_b_T3s, 12U, c83_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c83_b_Wf, 13U, c83_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b_T6snew, 14U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b_WG6new, 15U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b_h6new, 16U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b_f, 17U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 2);
  c83_WcoolPT2 = c83_b_WcoolPT * 0.43;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 3);
  c83_A = c83_b_Wf;
  c83_B = c83_b_WG6 - c83_b_Wf;
  c83_x = c83_A;
  c83_y = c83_B;
  c83_b_x = c83_x;
  c83_b_y = c83_y;
  c83_c_x = c83_b_x;
  c83_c_y = c83_b_y;
  c83_b_f = c83_c_x / c83_c_y;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 4);
  c83_b_A = c83_b_Wf;
  c83_b_B = (c83_b_WG6 + c83_WcoolPT2) - c83_b_Wf;
  c83_d_x = c83_b_A;
  c83_d_y = c83_b_B;
  c83_e_x = c83_d_x;
  c83_e_y = c83_d_y;
  c83_f_x = c83_e_x;
  c83_f_y = c83_e_y;
  c83_fnew = c83_f_x / c83_f_y;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 5);
  c83_c_A = c83_b_WG6 * c83_gashi(chartInstance, c83_b_T6s, c83_b_f) +
    c83_WcoolPT2 * c83_gashi(chartInstance, c83_b_T3s, 0.0);
  c83_c_B = c83_b_WG6 + c83_WcoolPT2;
  c83_g_x = c83_c_A;
  c83_g_y = c83_c_B;
  c83_h_x = c83_g_x;
  c83_h_y = c83_g_y;
  c83_i_x = c83_h_x;
  c83_i_y = c83_h_y;
  c83_b_h6new = c83_i_x / c83_i_y;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 6);
  c83_b_WG6new = c83_b_WG6 + c83_WcoolPT2;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 7);
  c83_a = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 8);
  c83_b = 5000.0;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 9);
  c83_error = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 10);
  while (CV_EML_WHILE(0, 1, 0, c83_error > 1.0E-9)) {
    _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 11);
    c83_d_A = c83_a + c83_b;
    c83_j_x = c83_d_A;
    c83_k_x = c83_j_x;
    c83_l_x = c83_k_x;
    c83_j_y = c83_l_x / 2.0;
    c83_h6newGuess = c83_gashi(chartInstance, c83_j_y, c83_fnew);
    _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 12);
    c83_e_A = c83_h6newGuess - c83_b_h6new;
    c83_d_B = c83_b_h6new;
    c83_m_x = c83_e_A;
    c83_k_y = c83_d_B;
    c83_n_x = c83_m_x;
    c83_l_y = c83_k_y;
    c83_o_x = c83_n_x;
    c83_m_y = c83_l_y;
    c83_n_y = c83_o_x / c83_m_y;
    c83_p_x = c83_n_y;
    c83_q_x = c83_p_x;
    c83_error = muDoubleScalarAbs(c83_q_x);
    _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 13);
    c83_Z = c83_h6newGuess - c83_b_h6new;
    _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 14);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c83_Z, 0.0, -1, 4U,
          c83_Z > 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 15);
      c83_f_A = c83_a + c83_b;
      c83_r_x = c83_f_A;
      c83_s_x = c83_r_x;
      c83_t_x = c83_s_x;
      c83_b = c83_t_x / 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 17);
      c83_g_A = c83_a + c83_b;
      c83_u_x = c83_g_A;
      c83_v_x = c83_u_x;
      c83_w_x = c83_v_x;
      c83_a = c83_w_x / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 10);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, 20);
  c83_h_A = c83_a + c83_b;
  c83_x_x = c83_h_A;
  c83_y_x = c83_x_x;
  c83_ab_x = c83_y_x;
  c83_b_T6snew = c83_ab_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c83_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c83_T6snew = c83_b_T6snew;
  *chartInstance->c83_WG6new = c83_b_WG6new;
  *chartInstance->c83_h6new = c83_b_h6new;
  *chartInstance->c83_f = c83_b_f;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c83_sfEvent);
}

static void initSimStructsc83_TSE_Path(SFc83_TSE_PathInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c83_gashi(SFc83_TSE_PathInstanceStruct *chartInstance, real_T
  c83_T, real_T c83_FuelAirRatio)
{
  real_T c83_Hi;
  uint32_T c83_debug_family_var_map[9];
  real_T c83_b_FuelAirRatio;
  real_T c83_TE;
  real_T c83_Hia;
  real_T c83_Hif;
  real_T c83_nargin = 2.0;
  real_T c83_nargout = 1.0;
  real_T c83_A;
  real_T c83_x;
  real_T c83_b_x;
  real_T c83_c_x;
  real_T c83_b_A;
  real_T c83_d_x;
  real_T c83_e_x;
  real_T c83_f_x;
  real_T c83_c_A;
  real_T c83_B;
  real_T c83_g_x;
  real_T c83_y;
  real_T c83_h_x;
  real_T c83_b_y;
  real_T c83_i_x;
  real_T c83_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c83_b_debug_family_names,
    c83_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_b_FuelAirRatio, 0U,
    c83_sf_marshallOut, c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_TE, 1U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_Hia, 2U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_Hif, 3U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_nargin, 4U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_nargout, 5U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_T, 6U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_FuelAirRatio, 7U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c83_Hi, 8U, c83_sf_marshallOut,
    c83_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 6);
  if (CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c83_FuelAirRatio, 0.0,
        -1, 2U, c83_FuelAirRatio < 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 7);
    c83_FuelAirRatio = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 10);
  if (CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c83_FuelAirRatio,
        0.067623, -1, 4U, c83_FuelAirRatio > 0.067623))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 11);
    c83_FuelAirRatio = 0.067623;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 14);
  c83_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 16);
  if (CV_SCRIPT_IF(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c83_FuelAirRatio, 0.0,
        -1, 0U, c83_FuelAirRatio == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 17);
    c83_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 21);
  c83_A = c83_T * 9.0;
  c83_x = c83_A;
  c83_b_x = c83_x;
  c83_c_x = c83_b_x;
  c83_TE = c83_c_x / 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 22);
  if (CV_SCRIPT_IF(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c83_TE, 300.0, -1, 2U,
        c83_TE < 300.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 23);
    c83_TE = 300.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 26);
  if (CV_SCRIPT_IF(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c83_TE, 4000.0, -1, 4U,
        c83_TE > 4000.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 27);
    c83_TE = 4000.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 31);
  c83_Hia = (((((((1.2644425E-26 * c83_TE - 2.0752522E-22) * c83_TE +
                  1.270263E-18) * c83_TE - 3.0256518E-15) * c83_TE -
                1.6794594E-12) * c83_TE + 2.1839826E-8) * c83_TE - 2.576844E-5) *
             c83_TE + 0.25020051) * c83_TE - 1.7558886;
  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 33);
  switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c83_b_FuelAirRatio)) {
   case 1:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 38);
    c83_Hi = c83_Hia * 2.3254259;
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 42);
    c83_Hif = (((((((9.0848388E-26 * c83_TE - 1.9050949E-21) * c83_TE +
                    1.7021525E-17) * c83_TE - 8.4102208E-14) * c83_TE +
                  2.4921698E-10) * c83_TE - 4.5906332E-7) * c83_TE +
                0.0006129315) * c83_TE + 0.073816638) * c83_TE + 30.58153;
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 43);
    c83_c_A = c83_Hia + c83_FuelAirRatio * c83_Hif;
    c83_B = 1.0 + c83_FuelAirRatio;
    c83_g_x = c83_c_A;
    c83_y = c83_B;
    c83_h_x = c83_g_x;
    c83_b_y = c83_y;
    c83_i_x = c83_h_x;
    c83_c_y = c83_b_y;
    c83_Hif = c83_i_x / c83_c_y;
    _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 46);
    c83_Hi = c83_Hif * 2.3254259;
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, 48);
  c83_b_A = c83_TE * 5.0;
  c83_d_x = c83_b_A;
  c83_e_x = c83_d_x;
  c83_f_x = c83_e_x;
  c83_T = c83_f_x / 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c83_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  return c83_Hi;
}

static void init_script_number_translation(uint32_T c83_machineNumber, uint32_T
  c83_chartNumber, uint32_T c83_instanceNumber)
{
  (void)c83_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c83_chartNumber, c83_instanceNumber, 0U,
    sf_debug_get_script_id(
    "I:\\MATLABWORK\\GTFEngine\\FunctionsLibrary\\gashi.m"));
}

static const mxArray *c83_sf_marshallOut(void *chartInstanceVoid, void
  *c83_inData)
{
  const mxArray *c83_mxArrayOutData = NULL;
  real_T c83_u;
  const mxArray *c83_y = NULL;
  SFc83_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc83_TSE_PathInstanceStruct *)chartInstanceVoid;
  c83_mxArrayOutData = NULL;
  c83_u = *(real_T *)c83_inData;
  c83_y = NULL;
  sf_mex_assign(&c83_y, sf_mex_create("y", &c83_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c83_mxArrayOutData, c83_y, false);
  return c83_mxArrayOutData;
}

static real_T c83_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c83_b_f, const char_T *c83_identifier)
{
  real_T c83_y;
  emlrtMsgIdentifier c83_thisId;
  c83_thisId.fIdentifier = c83_identifier;
  c83_thisId.fParent = NULL;
  c83_y = c83_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c83_b_f), &c83_thisId);
  sf_mex_destroy(&c83_b_f);
  return c83_y;
}

static real_T c83_b_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct *chartInstance,
  const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId)
{
  real_T c83_y;
  real_T c83_d0;
  (void)chartInstance;
  sf_mex_import(c83_parentId, sf_mex_dup(c83_u), &c83_d0, 1, 0, 0U, 0, 0U, 0);
  c83_y = c83_d0;
  sf_mex_destroy(&c83_u);
  return c83_y;
}

static void c83_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c83_mxArrayInData, const char_T *c83_varName, void *c83_outData)
{
  const mxArray *c83_b_f;
  const char_T *c83_identifier;
  emlrtMsgIdentifier c83_thisId;
  real_T c83_y;
  SFc83_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc83_TSE_PathInstanceStruct *)chartInstanceVoid;
  c83_b_f = sf_mex_dup(c83_mxArrayInData);
  c83_identifier = c83_varName;
  c83_thisId.fIdentifier = c83_identifier;
  c83_thisId.fParent = NULL;
  c83_y = c83_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c83_b_f), &c83_thisId);
  sf_mex_destroy(&c83_b_f);
  *(real_T *)c83_outData = c83_y;
  sf_mex_destroy(&c83_mxArrayInData);
}

const mxArray *sf_c83_TSE_Path_get_eml_resolved_functions_info(void)
{
  const mxArray *c83_nameCaptureInfo = NULL;
  c83_nameCaptureInfo = NULL;
  sf_mex_assign(&c83_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c83_info_helper(&c83_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c83_nameCaptureInfo);
  return c83_nameCaptureInfo;
}

static void c83_info_helper(const mxArray **c83_info)
{
  const mxArray *c83_rhs0 = NULL;
  const mxArray *c83_lhs0 = NULL;
  const mxArray *c83_rhs1 = NULL;
  const mxArray *c83_lhs1 = NULL;
  const mxArray *c83_rhs2 = NULL;
  const mxArray *c83_lhs2 = NULL;
  const mxArray *c83_rhs3 = NULL;
  const mxArray *c83_lhs3 = NULL;
  const mxArray *c83_rhs4 = NULL;
  const mxArray *c83_lhs4 = NULL;
  const mxArray *c83_rhs5 = NULL;
  const mxArray *c83_lhs5 = NULL;
  const mxArray *c83_rhs6 = NULL;
  const mxArray *c83_lhs6 = NULL;
  const mxArray *c83_rhs7 = NULL;
  const mxArray *c83_lhs7 = NULL;
  const mxArray *c83_rhs8 = NULL;
  const mxArray *c83_lhs8 = NULL;
  const mxArray *c83_rhs9 = NULL;
  const mxArray *c83_lhs9 = NULL;
  const mxArray *c83_rhs10 = NULL;
  const mxArray *c83_lhs10 = NULL;
  const mxArray *c83_rhs11 = NULL;
  const mxArray *c83_lhs11 = NULL;
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c83_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c83_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c83_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c83_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c83_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c83_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c83_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("gashi"), "name", "name", 7);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1428734872U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c83_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTFEngine/FunctionsLibrary/gashi.m"), "context", "context",
                  8);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("mrdivide"), "name", "name",
                  8);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c83_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("abs"), "name", "name", 9);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c83_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c83_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 11);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c83_info, c83_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c83_info, c83_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c83_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c83_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c83_info, sf_mex_duplicatearraysafe(&c83_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c83_rhs0);
  sf_mex_destroy(&c83_lhs0);
  sf_mex_destroy(&c83_rhs1);
  sf_mex_destroy(&c83_lhs1);
  sf_mex_destroy(&c83_rhs2);
  sf_mex_destroy(&c83_lhs2);
  sf_mex_destroy(&c83_rhs3);
  sf_mex_destroy(&c83_lhs3);
  sf_mex_destroy(&c83_rhs4);
  sf_mex_destroy(&c83_lhs4);
  sf_mex_destroy(&c83_rhs5);
  sf_mex_destroy(&c83_lhs5);
  sf_mex_destroy(&c83_rhs6);
  sf_mex_destroy(&c83_lhs6);
  sf_mex_destroy(&c83_rhs7);
  sf_mex_destroy(&c83_lhs7);
  sf_mex_destroy(&c83_rhs8);
  sf_mex_destroy(&c83_lhs8);
  sf_mex_destroy(&c83_rhs9);
  sf_mex_destroy(&c83_lhs9);
  sf_mex_destroy(&c83_rhs10);
  sf_mex_destroy(&c83_lhs10);
  sf_mex_destroy(&c83_rhs11);
  sf_mex_destroy(&c83_lhs11);
}

static const mxArray *c83_emlrt_marshallOut(const char * c83_u)
{
  const mxArray *c83_y = NULL;
  c83_y = NULL;
  sf_mex_assign(&c83_y, sf_mex_create("y", c83_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c83_u)), false);
  return c83_y;
}

static const mxArray *c83_b_emlrt_marshallOut(const uint32_T c83_u)
{
  const mxArray *c83_y = NULL;
  c83_y = NULL;
  sf_mex_assign(&c83_y, sf_mex_create("y", &c83_u, 7, 0U, 0U, 0U, 0), false);
  return c83_y;
}

static const mxArray *c83_b_sf_marshallOut(void *chartInstanceVoid, void
  *c83_inData)
{
  const mxArray *c83_mxArrayOutData = NULL;
  int32_T c83_u;
  const mxArray *c83_y = NULL;
  SFc83_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc83_TSE_PathInstanceStruct *)chartInstanceVoid;
  c83_mxArrayOutData = NULL;
  c83_u = *(int32_T *)c83_inData;
  c83_y = NULL;
  sf_mex_assign(&c83_y, sf_mex_create("y", &c83_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c83_mxArrayOutData, c83_y, false);
  return c83_mxArrayOutData;
}

static int32_T c83_c_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId)
{
  int32_T c83_y;
  int32_T c83_i0;
  (void)chartInstance;
  sf_mex_import(c83_parentId, sf_mex_dup(c83_u), &c83_i0, 1, 6, 0U, 0, 0U, 0);
  c83_y = c83_i0;
  sf_mex_destroy(&c83_u);
  return c83_y;
}

static void c83_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c83_mxArrayInData, const char_T *c83_varName, void *c83_outData)
{
  const mxArray *c83_b_sfEvent;
  const char_T *c83_identifier;
  emlrtMsgIdentifier c83_thisId;
  int32_T c83_y;
  SFc83_TSE_PathInstanceStruct *chartInstance;
  chartInstance = (SFc83_TSE_PathInstanceStruct *)chartInstanceVoid;
  c83_b_sfEvent = sf_mex_dup(c83_mxArrayInData);
  c83_identifier = c83_varName;
  c83_thisId.fIdentifier = c83_identifier;
  c83_thisId.fParent = NULL;
  c83_y = c83_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c83_b_sfEvent),
    &c83_thisId);
  sf_mex_destroy(&c83_b_sfEvent);
  *(int32_T *)c83_outData = c83_y;
  sf_mex_destroy(&c83_mxArrayInData);
}

static uint8_T c83_d_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_b_is_active_c83_TSE_Path, const char_T
  *c83_identifier)
{
  uint8_T c83_y;
  emlrtMsgIdentifier c83_thisId;
  c83_thisId.fIdentifier = c83_identifier;
  c83_thisId.fParent = NULL;
  c83_y = c83_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c83_b_is_active_c83_TSE_Path), &c83_thisId);
  sf_mex_destroy(&c83_b_is_active_c83_TSE_Path);
  return c83_y;
}

static uint8_T c83_e_emlrt_marshallIn(SFc83_TSE_PathInstanceStruct
  *chartInstance, const mxArray *c83_u, const emlrtMsgIdentifier *c83_parentId)
{
  uint8_T c83_y;
  uint8_T c83_u0;
  (void)chartInstance;
  sf_mex_import(c83_parentId, sf_mex_dup(c83_u), &c83_u0, 1, 3, 0U, 0, 0U, 0);
  c83_y = c83_u0;
  sf_mex_destroy(&c83_u);
  return c83_y;
}

static void init_dsm_address_info(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc83_TSE_PathInstanceStruct *chartInstance)
{
  chartInstance->c83_WG6 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c83_T6s = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c83_WcoolPT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c83_T3s = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c83_T6snew = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c83_Wf = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c83_WG6new = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c83_h6new = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c83_f = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c83_TSE_Path_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2363469447U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(478437952U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3004373159U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(559152237U);
}

mxArray* sf_c83_TSE_Path_get_post_codegen_info(void);
mxArray *sf_c83_TSE_Path_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jCZXtIW0XW8w55lNZ2gpGG");
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
    mxArray* mxPostCodegenInfo = sf_c83_TSE_Path_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c83_TSE_Path_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c83_TSE_Path_jit_fallback_info(void)
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

mxArray *sf_c83_TSE_Path_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c83_TSE_Path_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c83_TSE_Path(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"T6snew\",},{M[1],M[10],T\"WG6new\",},{M[1],M[12],T\"f\",},{M[1],M[11],T\"h6new\",},{M[8],M[0],T\"is_active_c83_TSE_Path\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c83_TSE_Path_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc83_TSE_PathInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc83_TSE_PathInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _TSE_PathMachineNumber_,
           83,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"WG6");
          _SFD_SET_DATA_PROPS(1,1,1,0,"T6s");
          _SFD_SET_DATA_PROPS(2,1,1,0,"WcoolPT");
          _SFD_SET_DATA_PROPS(3,1,1,0,"T3s");
          _SFD_SET_DATA_PROPS(4,2,0,1,"T6snew");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Wf");
          _SFD_SET_DATA_PROPS(6,2,0,1,"WG6new");
          _SFD_SET_DATA_PROPS(7,2,0,1,"h6new");
          _SFD_SET_DATA_PROPS(8,2,0,1,"f");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,443);
        _SFD_CV_INIT_EML_IF(0,1,0,355,361,385,416);
        _SFD_CV_INIT_EML_WHILE(0,1,0,233,250,420);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,358,361,-1,4);
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
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)c83_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)c83_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)c83_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c83_sf_marshallOut,(MexInFcnForType)c83_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c83_WG6);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c83_T6s);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c83_WcoolPT);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c83_T3s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c83_T6snew);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c83_Wf);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c83_WG6new);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c83_h6new);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c83_f);
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
  return "xRa3n1M84clqWxBr3ht0MG";
}

static void sf_opaque_initialize_c83_TSE_Path(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc83_TSE_PathInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*)
    chartInstanceVar);
  initialize_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c83_TSE_Path(void *chartInstanceVar)
{
  enable_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c83_TSE_Path(void *chartInstanceVar)
{
  disable_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c83_TSE_Path(void *chartInstanceVar)
{
  sf_gateway_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c83_TSE_Path(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c83_TSE_Path(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c83_TSE_Path(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc83_TSE_PathInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_TSE_Path_optimization_info();
    }

    finalize_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc83_TSE_Path((SFc83_TSE_PathInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c83_TSE_Path(SimStruct *S)
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
    initialize_params_c83_TSE_Path((SFc83_TSE_PathInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c83_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_TSE_Path_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      83);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,83,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,83,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,83);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,83,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,83,4);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,83);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2437683513U));
  ssSetChecksum1(S,(3705840493U));
  ssSetChecksum2(S,(868801346U));
  ssSetChecksum3(S,(4126143745U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c83_TSE_Path(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c83_TSE_Path(SimStruct *S)
{
  SFc83_TSE_PathInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc83_TSE_PathInstanceStruct *)utMalloc(sizeof
    (SFc83_TSE_PathInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc83_TSE_PathInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c83_TSE_Path;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c83_TSE_Path;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c83_TSE_Path;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c83_TSE_Path;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c83_TSE_Path;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c83_TSE_Path;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c83_TSE_Path;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c83_TSE_Path;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c83_TSE_Path;
  chartInstance->chartInfo.mdlStart = mdlStart_c83_TSE_Path;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c83_TSE_Path;
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

void c83_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c83_TSE_Path(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c83_TSE_Path(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c83_TSE_Path(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c83_TSE_Path_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
