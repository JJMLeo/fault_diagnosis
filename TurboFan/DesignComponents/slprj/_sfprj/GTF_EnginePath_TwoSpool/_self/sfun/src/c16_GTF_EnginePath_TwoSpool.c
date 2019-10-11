/* Include files */

#include <stddef.h>
#include "blas.h"
#include "GTF_EnginePath_TwoSpool_sfun.h"
#include "c16_GTF_EnginePath_TwoSpool.h"
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
static const char * c16_debug_family_names[33] = { "d_Sigma_Noz", "A_Noz", "f",
  "SigmaNoz", "h_out", "Cpg", "kg", "Rg", "PR_cr", "PR_use", "hs_outCal",
  "error", "a", "b", "hs_outGuess", "Z", "T9", "K_Noz", "q", "nargin", "nargout",
  "Pt_in", "Tt_in", "W_in", "Pamb", "Wf", "Pt8", "Tt8", "W8", "V", "Ma",
  "PR_Real", "P8" };

static const char * c16_b_debug_family_names[9] = { "b_FuelAirRatio", "TE",
  "Hia", "Hif", "nargin", "nargout", "T", "FuelAirRatio", "Hi" };

static const char * c16_c_debug_family_names[18] = { "amw", "R_eng",
  "b_FuelAirRatio", "Cpcal", "TO", "T", "TE", "Cpa", "Cpf", "nargin", "nargout",
  "TI", "FAR", "PRK", "Eff", "Cp", "k", "R" };

/* Function Declarations */
static void initialize_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initialize_params_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void enable_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void disable_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void set_sim_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_st);
static void finalize_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void sf_gateway_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void mdl_start_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void c16_chartstep_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static void initSimStructsc16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance);
static real_T c16_gashi(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_T, real_T c16_FuelAirRatio);
static void c16_gasstate(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_TI, real_T c16_FAR, real_T c16_PRK, real_T c16_Eff,
  real_T *c16_Cp, real_T *c16_k, real_T *c16_R);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_emlrt_marshallIn(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c16_b_P8, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static real_T c16_abs(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
                      real_T c16_x);
static real_T c16_mpower(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_a, real_T c16_b);
static void c16_eml_scalar_eg(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void c16_eml_error(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static real_T c16_sqrt(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_x);
static void c16_b_eml_error(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static real_T c16_b_mpower(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_a);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_c_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_d_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_b_is_active_c16_GTF_EnginePath_TwoSpool, const char_T *c16_identifier);
static uint8_T c16_e_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sqrt(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T *c16_x);
static void init_dsm_address_info(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_is_active_c16_GTF_EnginePath_TwoSpool = 0U;
}

static void initialize_params_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c16_update_debugger_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_b_hoistedGlobal;
  real_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_c_hoistedGlobal;
  real_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_d_hoistedGlobal;
  real_T c16_d_u;
  const mxArray *c16_e_y = NULL;
  real_T c16_e_hoistedGlobal;
  real_T c16_e_u;
  const mxArray *c16_f_y = NULL;
  real_T c16_f_hoistedGlobal;
  real_T c16_f_u;
  const mxArray *c16_g_y = NULL;
  real_T c16_g_hoistedGlobal;
  real_T c16_g_u;
  const mxArray *c16_h_y = NULL;
  uint8_T c16_h_hoistedGlobal;
  uint8_T c16_h_u;
  const mxArray *c16_i_y = NULL;
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(8, 1), false);
  c16_hoistedGlobal = *chartInstance->c16_Ma;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal = *chartInstance->c16_P8;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_c_hoistedGlobal = *chartInstance->c16_PR_Real;
  c16_c_u = c16_c_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  c16_d_hoistedGlobal = *chartInstance->c16_Pt8;
  c16_d_u = c16_d_hoistedGlobal;
  c16_e_y = NULL;
  sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 3, c16_e_y);
  c16_e_hoistedGlobal = *chartInstance->c16_Tt8;
  c16_e_u = c16_e_hoistedGlobal;
  c16_f_y = NULL;
  sf_mex_assign(&c16_f_y, sf_mex_create("y", &c16_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 4, c16_f_y);
  c16_f_hoistedGlobal = *chartInstance->c16_V;
  c16_f_u = c16_f_hoistedGlobal;
  c16_g_y = NULL;
  sf_mex_assign(&c16_g_y, sf_mex_create("y", &c16_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 5, c16_g_y);
  c16_g_hoistedGlobal = *chartInstance->c16_W8;
  c16_g_u = c16_g_hoistedGlobal;
  c16_h_y = NULL;
  sf_mex_assign(&c16_h_y, sf_mex_create("y", &c16_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 6, c16_h_y);
  c16_h_hoistedGlobal = chartInstance->c16_is_active_c16_GTF_EnginePath_TwoSpool;
  c16_h_u = c16_h_hoistedGlobal;
  c16_i_y = NULL;
  sf_mex_assign(&c16_i_y, sf_mex_create("y", &c16_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 7, c16_i_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_st)
{
  const mxArray *c16_u;
  chartInstance->c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  *chartInstance->c16_Ma = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 0)), "Ma");
  *chartInstance->c16_P8 = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 1)), "P8");
  *chartInstance->c16_PR_Real = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 2)), "PR_Real");
  *chartInstance->c16_Pt8 = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 3)), "Pt8");
  *chartInstance->c16_Tt8 = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 4)), "Tt8");
  *chartInstance->c16_V = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 5)), "V");
  *chartInstance->c16_W8 = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 6)), "W8");
  chartInstance->c16_is_active_c16_GTF_EnginePath_TwoSpool =
    c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 7)),
    "is_active_c16_GTF_EnginePath_TwoSpool");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_GTF_EnginePath_TwoSpool(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_GTF_EnginePath_TwoSpool(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GTF_EnginePath_TwoSpoolMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Pt8, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Tt8, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Pt_in, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Tt_in, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_W_in, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_W8, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_V, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Ma, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_PR_Real, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Pamb, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_Wf, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c16_P8, 11U);
}

static void mdl_start_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c16_chartstep_c16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  real_T c16_hoistedGlobal;
  real_T c16_b_hoistedGlobal;
  real_T c16_c_hoistedGlobal;
  real_T c16_d_hoistedGlobal;
  real_T c16_e_hoistedGlobal;
  real_T c16_b_Pt_in;
  real_T c16_b_Tt_in;
  real_T c16_b_W_in;
  real_T c16_b_Pamb;
  real_T c16_b_Wf;
  uint32_T c16_debug_family_var_map[33];
  real_T c16_d_Sigma_Noz;
  real_T c16_A_Noz;
  real_T c16_f;
  real_T c16_SigmaNoz;
  real_T c16_h_out;
  real_T c16_Cpg;
  real_T c16_kg;
  real_T c16_Rg;
  real_T c16_PR_cr;
  real_T c16_PR_use;
  real_T c16_hs_outCal;
  real_T c16_error;
  real_T c16_a;
  real_T c16_b;
  real_T c16_hs_outGuess;
  real_T c16_Z;
  real_T c16_T9;
  real_T c16_K_Noz;
  real_T c16_q;
  real_T c16_nargin = 5.0;
  real_T c16_nargout = 7.0;
  real_T c16_b_Pt8;
  real_T c16_b_Tt8;
  real_T c16_b_W8;
  real_T c16_b_V;
  real_T c16_b_Ma;
  real_T c16_b_PR_Real;
  real_T c16_b_P8;
  real_T c16_A;
  real_T c16_B;
  real_T c16_x;
  real_T c16_y;
  real_T c16_b_x;
  real_T c16_b_y;
  real_T c16_c_x;
  real_T c16_c_y;
  real_T c16_b_Rg;
  real_T c16_b_kg;
  real_T c16_b_Cpg;
  real_T c16_b_A;
  real_T c16_d_x;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_d_y;
  real_T c16_c_A;
  real_T c16_b_B;
  real_T c16_g_x;
  real_T c16_e_y;
  real_T c16_h_x;
  real_T c16_f_y;
  real_T c16_i_x;
  real_T c16_g_y;
  real_T c16_h_y;
  real_T c16_d_A;
  real_T c16_c_B;
  real_T c16_j_x;
  real_T c16_i_y;
  real_T c16_k_x;
  real_T c16_j_y;
  real_T c16_l_x;
  real_T c16_k_y;
  real_T c16_e_A;
  real_T c16_d_B;
  real_T c16_m_x;
  real_T c16_l_y;
  real_T c16_n_x;
  real_T c16_m_y;
  real_T c16_o_x;
  real_T c16_n_y;
  real_T c16_f_A;
  real_T c16_e_B;
  real_T c16_p_x;
  real_T c16_o_y;
  real_T c16_q_x;
  real_T c16_p_y;
  real_T c16_r_x;
  real_T c16_q_y;
  real_T c16_r_y;
  real_T c16_d0;
  real_T c16_g_A;
  real_T c16_s_x;
  real_T c16_t_x;
  real_T c16_u_x;
  real_T c16_s_y;
  real_T c16_h_A;
  real_T c16_f_B;
  real_T c16_v_x;
  real_T c16_t_y;
  real_T c16_w_x;
  real_T c16_u_y;
  real_T c16_x_x;
  real_T c16_v_y;
  real_T c16_w_y;
  real_T c16_i_A;
  real_T c16_y_x;
  real_T c16_ab_x;
  real_T c16_bb_x;
  real_T c16_j_A;
  real_T c16_cb_x;
  real_T c16_db_x;
  real_T c16_eb_x;
  real_T c16_k_A;
  real_T c16_fb_x;
  real_T c16_gb_x;
  real_T c16_hb_x;
  real_T c16_l_A;
  real_T c16_g_B;
  real_T c16_ib_x;
  real_T c16_x_y;
  real_T c16_jb_x;
  real_T c16_y_y;
  real_T c16_kb_x;
  real_T c16_ab_y;
  real_T c16_m_A;
  real_T c16_h_B;
  real_T c16_lb_x;
  real_T c16_bb_y;
  real_T c16_mb_x;
  real_T c16_cb_y;
  real_T c16_nb_x;
  real_T c16_db_y;
  real_T c16_n_A;
  real_T c16_i_B;
  real_T c16_ob_x;
  real_T c16_eb_y;
  real_T c16_pb_x;
  real_T c16_fb_y;
  real_T c16_qb_x;
  real_T c16_gb_y;
  real_T c16_o_A;
  real_T c16_j_B;
  real_T c16_rb_x;
  real_T c16_hb_y;
  real_T c16_sb_x;
  real_T c16_ib_y;
  real_T c16_tb_x;
  real_T c16_jb_y;
  real_T c16_kb_y;
  real_T c16_ub_x;
  real_T c16_vb_x;
  real_T c16_p_A;
  real_T c16_k_B;
  real_T c16_wb_x;
  real_T c16_lb_y;
  real_T c16_xb_x;
  real_T c16_mb_y;
  real_T c16_yb_x;
  real_T c16_nb_y;
  real_T c16_q_A;
  real_T c16_l_B;
  real_T c16_ac_x;
  real_T c16_ob_y;
  real_T c16_bc_x;
  real_T c16_pb_y;
  real_T c16_cc_x;
  real_T c16_qb_y;
  real_T c16_rb_y;
  real_T c16_m_B;
  real_T c16_sb_y;
  real_T c16_tb_y;
  real_T c16_ub_y;
  real_T c16_vb_y;
  real_T c16_r_A;
  real_T c16_n_B;
  real_T c16_dc_x;
  real_T c16_wb_y;
  real_T c16_ec_x;
  real_T c16_xb_y;
  real_T c16_fc_x;
  real_T c16_yb_y;
  real_T c16_ac_y;
  real_T c16_gc_x;
  real_T c16_hc_x;
  real_T c16_o_B;
  real_T c16_bc_y;
  real_T c16_cc_y;
  real_T c16_dc_y;
  real_T c16_ec_y;
  real_T c16_s_A;
  real_T c16_p_B;
  real_T c16_ic_x;
  real_T c16_fc_y;
  real_T c16_jc_x;
  real_T c16_gc_y;
  real_T c16_kc_x;
  real_T c16_hc_y;
  real_T c16_ic_y;
  real_T c16_lc_x;
  real_T c16_mc_x;
  real_T c16_t_A;
  real_T c16_q_B;
  real_T c16_nc_x;
  real_T c16_jc_y;
  real_T c16_oc_x;
  real_T c16_kc_y;
  real_T c16_pc_x;
  real_T c16_lc_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *chartInstance->c16_Pt_in;
  c16_b_hoistedGlobal = *chartInstance->c16_Tt_in;
  c16_c_hoistedGlobal = *chartInstance->c16_W_in;
  c16_d_hoistedGlobal = *chartInstance->c16_Pamb;
  c16_e_hoistedGlobal = *chartInstance->c16_Wf;
  c16_b_Pt_in = c16_hoistedGlobal;
  c16_b_Tt_in = c16_b_hoistedGlobal;
  c16_b_W_in = c16_c_hoistedGlobal;
  c16_b_Pamb = c16_d_hoistedGlobal;
  c16_b_Wf = c16_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_d_Sigma_Noz, 0U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_A_Noz, 1U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_f, 2U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_SigmaNoz, 3U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_h_out, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Cpg, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_kg, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Rg, 7U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_PR_cr, 8U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_PR_use, 9U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_hs_outCal, 10U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_error, 11U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_a, 12U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b, 13U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_hs_outGuess, 14U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Z, 15U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_T9, 16U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_K_Noz, 17U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_q, 18U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 19U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 20U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_Pt_in, 21U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_Tt_in, 22U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_W_in, 23U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_Pamb, 24U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_b_Wf, 25U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_Pt8, 26U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_Tt8, 27U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_W8, 28U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_V, 29U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_Ma, 30U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_PR_Real, 31U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_P8, 32U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 3);
  c16_d_Sigma_Noz = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 4);
  c16_A_Noz = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_A = c16_b_Wf;
  c16_B = c16_b_W_in - c16_b_Wf;
  c16_x = c16_A;
  c16_y = c16_B;
  c16_b_x = c16_x;
  c16_b_y = c16_y;
  c16_c_x = c16_b_x;
  c16_c_y = c16_b_y;
  c16_f = c16_c_x / c16_c_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  c16_SigmaNoz = 0.99;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  c16_b_Pt8 = c16_b_Pt_in * 0.99;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 12);
  c16_b_Tt8 = c16_b_Tt_in;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 13);
  c16_h_out = c16_gashi(chartInstance, c16_b_Tt_in, c16_f);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 16);
  c16_gasstate(chartInstance, c16_b_Tt8, c16_f, 1.0, 1.0, &c16_b_Cpg, &c16_b_kg,
               &c16_b_Rg);
  c16_Cpg = c16_b_Cpg;
  c16_kg = c16_b_kg;
  c16_Rg = c16_b_Rg;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 19);
  c16_b_A = c16_kg + 1.0;
  c16_d_x = c16_b_A;
  c16_e_x = c16_d_x;
  c16_f_x = c16_e_x;
  c16_d_y = c16_f_x / 2.0;
  c16_c_A = c16_kg;
  c16_b_B = c16_kg - 1.0;
  c16_g_x = c16_c_A;
  c16_e_y = c16_b_B;
  c16_h_x = c16_g_x;
  c16_f_y = c16_e_y;
  c16_i_x = c16_h_x;
  c16_g_y = c16_f_y;
  c16_h_y = c16_i_x / c16_g_y;
  c16_PR_cr = c16_mpower(chartInstance, c16_d_y, c16_h_y);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 22);
  c16_d_A = c16_b_Pt_in;
  c16_c_B = c16_b_Pamb;
  c16_j_x = c16_d_A;
  c16_i_y = c16_c_B;
  c16_k_x = c16_j_x;
  c16_j_y = c16_i_y;
  c16_l_x = c16_k_x;
  c16_k_y = c16_j_y;
  c16_PR_use = c16_l_x / c16_k_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 25);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c16_PR_use, c16_PR_cr, -1,
        2U, c16_PR_use < c16_PR_cr))) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 26);
    c16_b_P8 = c16_b_Pamb;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 28);
    c16_e_A = c16_b_Pt_in;
    c16_d_B = c16_b_P8;
    c16_m_x = c16_e_A;
    c16_l_y = c16_d_B;
    c16_n_x = c16_m_x;
    c16_m_y = c16_l_y;
    c16_o_x = c16_n_x;
    c16_n_y = c16_m_y;
    c16_b_PR_Real = c16_o_x / c16_n_y;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 29);
    c16_f_A = 1.0 - c16_kg;
    c16_e_B = c16_kg;
    c16_p_x = c16_f_A;
    c16_o_y = c16_e_B;
    c16_q_x = c16_p_x;
    c16_p_y = c16_o_y;
    c16_r_x = c16_q_x;
    c16_q_y = c16_p_y;
    c16_r_y = c16_r_x / c16_q_y;
    c16_d0 = 2.0 * c16_Cpg * c16_b_Tt8 * (1.0 - c16_mpower(chartInstance,
      c16_b_PR_Real, c16_r_y));
    c16_b_sqrt(chartInstance, &c16_d0);
    c16_b_V = c16_d0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 30);
    c16_hs_outCal = c16_h_out - 0.5 * c16_b_V * c16_b_V * 0.001;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 31);
    c16_error = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 32);
    c16_a = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 33);
    c16_b = 3000.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 34);
    while (CV_EML_WHILE(0, 1, 0, c16_error >= 1.0E-9)) {
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 35);
      c16_g_A = c16_a + c16_b;
      c16_s_x = c16_g_A;
      c16_t_x = c16_s_x;
      c16_u_x = c16_t_x;
      c16_s_y = c16_u_x / 2.0;
      c16_hs_outGuess = c16_gashi(chartInstance, c16_s_y, c16_f);
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 36);
      c16_Z = c16_hs_outGuess - c16_hs_outCal;
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 37);
      c16_h_A = c16_hs_outGuess - c16_hs_outCal;
      c16_f_B = c16_hs_outCal;
      c16_v_x = c16_h_A;
      c16_t_y = c16_f_B;
      c16_w_x = c16_v_x;
      c16_u_y = c16_t_y;
      c16_x_x = c16_w_x;
      c16_v_y = c16_u_y;
      c16_w_y = c16_x_x / c16_v_y;
      c16_error = c16_abs(chartInstance, c16_w_y);
      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 38);
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c16_Z, 0.0, -1, 4U,
            c16_Z > 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 39);
        c16_i_A = c16_a + c16_b;
        c16_y_x = c16_i_A;
        c16_ab_x = c16_y_x;
        c16_bb_x = c16_ab_x;
        c16_b = c16_bb_x / 2.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 41);
        c16_j_A = c16_a + c16_b;
        c16_cb_x = c16_j_A;
        c16_db_x = c16_cb_x;
        c16_eb_x = c16_db_x;
        c16_a = c16_eb_x / 2.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 34);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 44);
    c16_k_A = c16_a + c16_b;
    c16_fb_x = c16_k_A;
    c16_gb_x = c16_fb_x;
    c16_hb_x = c16_gb_x;
    c16_T9 = c16_hb_x / 2.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 45);
    c16_l_A = c16_b_V;
    c16_g_B = c16_kg * c16_Rg * c16_T9;
    c16_b_sqrt(chartInstance, &c16_g_B);
    c16_ib_x = c16_l_A;
    c16_x_y = c16_g_B;
    c16_jb_x = c16_ib_x;
    c16_y_y = c16_x_y;
    c16_kb_x = c16_jb_x;
    c16_ab_y = c16_y_y;
    c16_b_Ma = c16_kb_x / c16_ab_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 47);
    c16_m_A = c16_b_Pt_in;
    c16_h_B = c16_PR_cr;
    c16_lb_x = c16_m_A;
    c16_bb_y = c16_h_B;
    c16_mb_x = c16_lb_x;
    c16_cb_y = c16_bb_y;
    c16_nb_x = c16_mb_x;
    c16_db_y = c16_cb_y;
    c16_b_P8 = c16_nb_x / c16_db_y;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 49);
    c16_n_A = c16_b_Pt_in;
    c16_i_B = c16_b_P8;
    c16_ob_x = c16_n_A;
    c16_eb_y = c16_i_B;
    c16_pb_x = c16_ob_x;
    c16_fb_y = c16_eb_y;
    c16_qb_x = c16_pb_x;
    c16_gb_y = c16_fb_y;
    c16_b_PR_Real = c16_qb_x / c16_gb_y;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 50);
    c16_o_A = 1.0 - c16_kg;
    c16_j_B = c16_kg;
    c16_rb_x = c16_o_A;
    c16_hb_y = c16_j_B;
    c16_sb_x = c16_rb_x;
    c16_ib_y = c16_hb_y;
    c16_tb_x = c16_sb_x;
    c16_jb_y = c16_ib_y;
    c16_kb_y = c16_tb_x / c16_jb_y;
    c16_ub_x = 2.0 * c16_Cpg * c16_b_Tt8 * (1.0 - c16_mpower(chartInstance,
      c16_b_PR_Real, c16_kb_y));
    c16_b_V = c16_ub_x;
    if (c16_b_V < 0.0) {
      c16_b_eml_error(chartInstance);
    }

    c16_vb_x = c16_b_V;
    c16_b_V = c16_vb_x;
    c16_b_V = muDoubleScalarSqrt(c16_b_V);
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 51);
    c16_b_Ma = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 52);
    c16_p_A = c16_b_mpower(chartInstance, c16_b_V);
    c16_k_B = c16_kg * c16_Rg;
    c16_wb_x = c16_p_A;
    c16_lb_y = c16_k_B;
    c16_xb_x = c16_wb_x;
    c16_mb_y = c16_lb_y;
    c16_yb_x = c16_xb_x;
    c16_nb_y = c16_mb_y;
    c16_T9 = c16_yb_x / c16_nb_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 56);
  c16_q_A = c16_kg;
  c16_l_B = c16_Rg;
  c16_ac_x = c16_q_A;
  c16_ob_y = c16_l_B;
  c16_bc_x = c16_ac_x;
  c16_pb_y = c16_ob_y;
  c16_cc_x = c16_bc_x;
  c16_qb_y = c16_pb_y;
  c16_rb_y = c16_cc_x / c16_qb_y;
  c16_m_B = c16_kg + 1.0;
  c16_sb_y = c16_m_B;
  c16_tb_y = c16_sb_y;
  c16_ub_y = c16_tb_y;
  c16_vb_y = 2.0 / c16_ub_y;
  c16_r_A = c16_kg + 1.0;
  c16_n_B = c16_kg - 1.0;
  c16_dc_x = c16_r_A;
  c16_wb_y = c16_n_B;
  c16_ec_x = c16_dc_x;
  c16_xb_y = c16_wb_y;
  c16_fc_x = c16_ec_x;
  c16_yb_y = c16_xb_y;
  c16_ac_y = c16_fc_x / c16_yb_y;
  c16_gc_x = c16_rb_y * c16_mpower(chartInstance, c16_vb_y, c16_ac_y);
  c16_K_Noz = c16_gc_x;
  if (c16_K_Noz < 0.0) {
    c16_b_eml_error(chartInstance);
  }

  c16_hc_x = c16_K_Noz;
  c16_K_Noz = c16_hc_x;
  c16_K_Noz = muDoubleScalarSqrt(c16_K_Noz);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 59);
  c16_o_B = c16_kg + 1.0;
  c16_bc_y = c16_o_B;
  c16_cc_y = c16_bc_y;
  c16_dc_y = c16_cc_y;
  c16_ec_y = 2.0 / c16_dc_y;
  c16_s_A = c16_kg + 1.0;
  c16_p_B = 2.0 * (1.0 - c16_kg);
  c16_ic_x = c16_s_A;
  c16_fc_y = c16_p_B;
  c16_jc_x = c16_ic_x;
  c16_gc_y = c16_fc_y;
  c16_kc_x = c16_jc_x;
  c16_hc_y = c16_gc_y;
  c16_ic_y = c16_kc_x / c16_hc_y;
  c16_q = c16_b_Ma * c16_mpower(chartInstance, c16_ec_y * (1.0 + 0.5 * (c16_kg -
    1.0) * c16_b_mpower(chartInstance, c16_b_Ma)), c16_ic_y);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 62);
  c16_lc_x = c16_b_Tt8;
  c16_mc_x = c16_lc_x;
  if (c16_mc_x < 0.0) {
    c16_b_eml_error(chartInstance);
  }

  c16_mc_x = muDoubleScalarSqrt(c16_mc_x);
  c16_t_A = c16_K_Noz * c16_q * c16_b_Pt8;
  c16_q_B = c16_mc_x;
  c16_nc_x = c16_t_A;
  c16_jc_y = c16_q_B;
  c16_oc_x = c16_nc_x;
  c16_kc_y = c16_jc_y;
  c16_pc_x = c16_oc_x;
  c16_lc_y = c16_kc_y;
  c16_b_W8 = c16_pc_x / c16_lc_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c16_Pt8 = c16_b_Pt8;
  *chartInstance->c16_Tt8 = c16_b_Tt8;
  *chartInstance->c16_W8 = c16_b_W8;
  *chartInstance->c16_V = c16_b_V;
  *chartInstance->c16_Ma = c16_b_Ma;
  *chartInstance->c16_PR_Real = c16_b_PR_Real;
  *chartInstance->c16_P8 = c16_b_P8;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_GTF_EnginePath_TwoSpool
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c16_gashi(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_T, real_T c16_FuelAirRatio)
{
  real_T c16_Hi;
  uint32_T c16_debug_family_var_map[9];
  real_T c16_b_FuelAirRatio;
  real_T c16_TE;
  real_T c16_Hia;
  real_T c16_Hif;
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_A;
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_b_A;
  real_T c16_d_x;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_c_A;
  real_T c16_B;
  real_T c16_g_x;
  real_T c16_y;
  real_T c16_h_x;
  real_T c16_b_y;
  real_T c16_i_x;
  real_T c16_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c16_b_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_FuelAirRatio, 0U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_TE, 1U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Hia, 2U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Hif, 3U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_T, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_FuelAirRatio, 7U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Hi, 8U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 6);
  if (CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c16_FuelAirRatio, 0.0,
        -1, 2U, c16_FuelAirRatio < 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 7);
    c16_FuelAirRatio = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 10);
  if (CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c16_FuelAirRatio,
        0.067623, -1, 4U, c16_FuelAirRatio > 0.067623))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 11);
    c16_FuelAirRatio = 0.067623;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 14);
  c16_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 16);
  if (CV_SCRIPT_IF(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c16_FuelAirRatio, 0.0,
        -1, 0U, c16_FuelAirRatio == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 17);
    c16_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 21);
  c16_A = c16_T * 9.0;
  c16_x = c16_A;
  c16_b_x = c16_x;
  c16_c_x = c16_b_x;
  c16_TE = c16_c_x / 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 22);
  if (CV_SCRIPT_IF(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c16_TE, 300.0, -1, 2U,
        c16_TE < 300.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 23);
    c16_TE = 300.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 26);
  if (CV_SCRIPT_IF(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c16_TE, 4000.0, -1, 4U,
        c16_TE > 4000.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 27);
    c16_TE = 4000.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 31);
  c16_Hia = (((((((1.2644425E-26 * c16_TE - 2.0752522E-22) * c16_TE +
                  1.270263E-18) * c16_TE - 3.0256518E-15) * c16_TE -
                1.6794594E-12) * c16_TE + 2.1839826E-8) * c16_TE - 2.576844E-5) *
             c16_TE + 0.25020051) * c16_TE - 1.7558886;
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 33);
  switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c16_b_FuelAirRatio)) {
   case 1:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 38);
    c16_Hi = c16_Hia * 2.3254259;
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 42);
    c16_Hif = (((((((9.0848388E-26 * c16_TE - 1.9050949E-21) * c16_TE +
                    1.7021525E-17) * c16_TE - 8.4102208E-14) * c16_TE +
                  2.4921698E-10) * c16_TE - 4.5906332E-7) * c16_TE +
                0.0006129315) * c16_TE + 0.073816638) * c16_TE + 30.58153;
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 43);
    c16_c_A = c16_Hia + c16_FuelAirRatio * c16_Hif;
    c16_B = 1.0 + c16_FuelAirRatio;
    c16_g_x = c16_c_A;
    c16_y = c16_B;
    c16_h_x = c16_g_x;
    c16_b_y = c16_y;
    c16_i_x = c16_h_x;
    c16_c_y = c16_b_y;
    c16_Hif = c16_i_x / c16_c_y;
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 46);
    c16_Hi = c16_Hif * 2.3254259;
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 48);
  c16_b_A = c16_TE * 5.0;
  c16_d_x = c16_b_A;
  c16_e_x = c16_d_x;
  c16_f_x = c16_e_x;
  c16_T = c16_f_x / 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  return c16_Hi;
}

static void c16_gasstate(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_TI, real_T c16_FAR, real_T c16_PRK, real_T c16_Eff,
  real_T *c16_Cp, real_T *c16_k, real_T *c16_R)
{
  uint32_T c16_debug_family_var_map[18];
  real_T c16_amw;
  real_T c16_R_eng;
  real_T c16_b_FuelAirRatio;
  real_T c16_Cpcal;
  real_T c16_TO;
  real_T c16_T;
  real_T c16_TE;
  real_T c16_Cpa;
  real_T c16_Cpf;
  real_T c16_nargin = 4.0;
  real_T c16_nargout = 3.0;
  real_T c16_B;
  real_T c16_y;
  real_T c16_b_y;
  real_T c16_c_y;
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_d_y;
  real_T c16_A;
  real_T c16_b_B;
  real_T c16_c_x;
  real_T c16_e_y;
  real_T c16_d_x;
  real_T c16_f_y;
  real_T c16_e_x;
  real_T c16_g_y;
  real_T c16_b_A;
  real_T c16_c_B;
  real_T c16_f_x;
  real_T c16_h_y;
  real_T c16_g_x;
  real_T c16_i_y;
  real_T c16_h_x;
  real_T c16_j_y;
  real_T c16_k_y;
  real_T c16_c_A;
  real_T c16_d_B;
  real_T c16_i_x;
  real_T c16_l_y;
  real_T c16_j_x;
  real_T c16_m_y;
  real_T c16_k_x;
  real_T c16_n_y;
  real_T c16_o_y;
  real_T c16_d_A;
  real_T c16_l_x;
  real_T c16_m_x;
  real_T c16_n_x;
  real_T c16_e_A;
  real_T c16_o_x;
  real_T c16_p_x;
  real_T c16_q_x;
  real_T c16_f_A;
  real_T c16_e_B;
  real_T c16_r_x;
  real_T c16_p_y;
  real_T c16_s_x;
  real_T c16_q_y;
  real_T c16_t_x;
  real_T c16_r_y;
  real_T c16_g_A;
  real_T c16_f_B;
  real_T c16_u_x;
  real_T c16_s_y;
  real_T c16_v_x;
  real_T c16_t_y;
  real_T c16_w_x;
  real_T c16_u_y;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c16_c_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_amw, 0U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_R_eng, 1U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_b_FuelAirRatio, 2U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Cpcal, 3U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_TO, 4U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_T, 5U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_TE, 6U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Cpa, 7U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Cpf, 8U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 9U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 10U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_TI, 11U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_FAR, 12U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_PRK, 13U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Eff, 14U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_Cp, 15U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_k, 16U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_R, 17U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 4);
  c16_amw = 28.97 - 0.946186 * c16_FAR;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 5);
  c16_B = c16_amw;
  c16_y = c16_B;
  c16_b_y = c16_y;
  c16_c_y = c16_b_y;
  c16_R_eng = 1.986375 / c16_c_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 6);
  *c16_R = c16_R_eng * 4185.7666;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 8);
  if (CV_SCRIPT_IF(1, 0, CV_RELATIONAL_EVAL(14U, 1U, 0, c16_FAR, 0.0, -1, 2U,
        c16_FAR < 0.0))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 9);
    c16_FAR = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 11);
  if (CV_SCRIPT_IF(1, 1, CV_RELATIONAL_EVAL(14U, 1U, 1, c16_FAR, 0.067623, -1,
        4U, c16_FAR > 0.067623))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 12);
    c16_FAR = 0.067623;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 15);
  c16_b_FuelAirRatio = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 16);
  if (CV_SCRIPT_IF(1, 2, CV_RELATIONAL_EVAL(14U, 1U, 2, c16_FAR, 0.0, -1, 0U,
        c16_FAR == 0.0))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 17);
    c16_b_FuelAirRatio = 1.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 20);
  *c16_Cp = 1100.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 21);
  c16_Cpcal = 1200.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 23);
  do {
    exitg1 = 0;
    c16_x = *c16_Cp - c16_Cpcal;
    c16_b_x = c16_x;
    c16_d_y = muDoubleScalarAbs(c16_b_x);
    if (CV_SCRIPT_WHILE(1, 0, c16_d_y - 1.0E-7 * c16_Cpcal > 0.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 24);
      *c16_Cp = c16_Cpcal;
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 25);
      c16_A = *c16_Cp;
      c16_b_B = *c16_Cp - *c16_R;
      c16_c_x = c16_A;
      c16_e_y = c16_b_B;
      c16_d_x = c16_c_x;
      c16_f_y = c16_e_y;
      c16_e_x = c16_d_x;
      c16_g_y = c16_f_y;
      *c16_k = c16_e_x / c16_g_y;
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 26);
      c16_b_A = *c16_k - 1.0;
      c16_c_B = *c16_k;
      c16_f_x = c16_b_A;
      c16_h_y = c16_c_B;
      c16_g_x = c16_f_x;
      c16_i_y = c16_h_y;
      c16_h_x = c16_g_x;
      c16_j_y = c16_i_y;
      c16_k_y = c16_h_x / c16_j_y;
      c16_c_A = c16_mpower(chartInstance, c16_PRK, c16_k_y) - 1.0;
      c16_d_B = c16_Eff;
      c16_i_x = c16_c_A;
      c16_l_y = c16_d_B;
      c16_j_x = c16_i_x;
      c16_m_y = c16_l_y;
      c16_k_x = c16_j_x;
      c16_n_y = c16_m_y;
      c16_o_y = c16_k_x / c16_n_y;
      c16_TO = c16_TI * (1.0 + c16_o_y);
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 27);
      c16_d_A = c16_TI + c16_TO;
      c16_l_x = c16_d_A;
      c16_m_x = c16_l_x;
      c16_n_x = c16_m_x;
      c16_T = c16_n_x / 2.0;
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 29);
      c16_e_A = c16_T * 9.0;
      c16_o_x = c16_e_A;
      c16_p_x = c16_o_x;
      c16_q_x = c16_p_x;
      c16_TE = c16_q_x / 5.0;
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 30);
      if (CV_SCRIPT_IF(1, 3, CV_RELATIONAL_EVAL(14U, 1U, 3, c16_TE, 300.0, -1,
            2U, c16_TE < 300.0))) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 31);
        c16_TE = 300.0;
      }

      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 33);
      if (CV_SCRIPT_IF(1, 4, CV_RELATIONAL_EVAL(14U, 1U, 4, c16_TE, 4000.0, -1,
            4U, c16_TE > 4000.0))) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 34);
        c16_TE = 4000.0;
      }

      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 38);
      c16_Cpa = ((((((1.011554E-25 * c16_TE - 1.452677E-21) * c16_TE +
                     7.6215767E-18) * c16_TE - 1.5128259E-14) * c16_TE -
                   6.7178376E-12) * c16_TE + 6.5519486E-8) * c16_TE -
                 5.1536879E-5) * c16_TE + 0.25020051;
      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 40);
      switch ((int32_T)_SFD_INTEGER_CHECK("b_FuelAirRatio", c16_b_FuelAirRatio))
      {
       case 1:
        CV_SCRIPT_SWITCH(1, 0, 1);
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 44);
        c16_Cpcal = c16_Cpa * 4185.7666;
        break;

       default:
        CV_SCRIPT_SWITCH(1, 0, 0);
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 47);
        c16_Cpf = ((((((7.267871E-25 * c16_TE - 1.3335668E-20) * c16_TE +
                       1.0212913E-16) * c16_TE - 4.2051104E-13) * c16_TE +
                     9.9686793E-10) * c16_TE - 1.3771901E-6) * c16_TE +
                   0.001225863) * c16_TE + 0.073816638;
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 48);
        c16_g_A = c16_Cpa + c16_FAR * c16_Cpf;
        c16_f_B = 1.0 + c16_FAR;
        c16_u_x = c16_g_A;
        c16_s_y = c16_f_B;
        c16_v_x = c16_u_x;
        c16_t_y = c16_s_y;
        c16_w_x = c16_v_x;
        c16_u_y = c16_t_y;
        c16_Cpf = c16_w_x / c16_u_y;
        _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 51);
        c16_Cpcal = c16_Cpf * 4185.7666;
        break;
      }

      _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 23);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 57);
  c16_f_A = *c16_Cp;
  c16_e_B = *c16_Cp - *c16_R;
  c16_r_x = c16_f_A;
  c16_p_y = c16_e_B;
  c16_s_x = c16_r_x;
  c16_q_y = c16_p_y;
  c16_t_x = c16_s_x;
  c16_r_y = c16_q_y;
  *c16_k = c16_t_x / c16_r_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, 59);
  *c16_Cp = c16_Cpcal;
  _SFD_SCRIPT_CALL(1U, chartInstance->c16_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c16_chartNumber, c16_instanceNumber, 0U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\gashi.m"));
  _SFD_SCRIPT_TRANSLATION(c16_chartNumber, c16_instanceNumber, 1U,
    sf_debug_get_script_id("I:\\MATLABWORK\\GTF\\FunctionsLibrary\\gasstate.m"));
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_emlrt_marshallIn(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c16_b_P8, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P8),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P8);
  return c16_y;
}

static real_T c16_b_emlrt_marshallIn(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d1;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d1, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d1;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_P8;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c16_b_P8 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P8),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P8);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 33, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  const mxArray *c16_rhs7 = NULL;
  const mxArray *c16_lhs7 = NULL;
  const mxArray *c16_rhs8 = NULL;
  const mxArray *c16_lhs8 = NULL;
  const mxArray *c16_rhs9 = NULL;
  const mxArray *c16_lhs9 = NULL;
  const mxArray *c16_rhs10 = NULL;
  const mxArray *c16_lhs10 = NULL;
  const mxArray *c16_rhs11 = NULL;
  const mxArray *c16_lhs11 = NULL;
  const mxArray *c16_rhs12 = NULL;
  const mxArray *c16_lhs12 = NULL;
  const mxArray *c16_rhs13 = NULL;
  const mxArray *c16_lhs13 = NULL;
  const mxArray *c16_rhs14 = NULL;
  const mxArray *c16_lhs14 = NULL;
  const mxArray *c16_rhs15 = NULL;
  const mxArray *c16_lhs15 = NULL;
  const mxArray *c16_rhs16 = NULL;
  const mxArray *c16_lhs16 = NULL;
  const mxArray *c16_rhs17 = NULL;
  const mxArray *c16_lhs17 = NULL;
  const mxArray *c16_rhs18 = NULL;
  const mxArray *c16_lhs18 = NULL;
  const mxArray *c16_rhs19 = NULL;
  const mxArray *c16_lhs19 = NULL;
  const mxArray *c16_rhs20 = NULL;
  const mxArray *c16_lhs20 = NULL;
  const mxArray *c16_rhs21 = NULL;
  const mxArray *c16_lhs21 = NULL;
  const mxArray *c16_rhs22 = NULL;
  const mxArray *c16_lhs22 = NULL;
  const mxArray *c16_rhs23 = NULL;
  const mxArray *c16_lhs23 = NULL;
  const mxArray *c16_rhs24 = NULL;
  const mxArray *c16_lhs24 = NULL;
  const mxArray *c16_rhs25 = NULL;
  const mxArray *c16_lhs25 = NULL;
  const mxArray *c16_rhs26 = NULL;
  const mxArray *c16_lhs26 = NULL;
  const mxArray *c16_rhs27 = NULL;
  const mxArray *c16_lhs27 = NULL;
  const mxArray *c16_rhs28 = NULL;
  const mxArray *c16_lhs28 = NULL;
  const mxArray *c16_rhs29 = NULL;
  const mxArray *c16_lhs29 = NULL;
  const mxArray *c16_rhs30 = NULL;
  const mxArray *c16_lhs30 = NULL;
  const mxArray *c16_rhs31 = NULL;
  const mxArray *c16_lhs31 = NULL;
  const mxArray *c16_rhs32 = NULL;
  const mxArray *c16_lhs32 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1389692574U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1386398752U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("gashi"), "name", "name", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gashi.m"), "resolved", "resolved", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1428734872U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c16_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gashi.m"), "context", "context", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c16_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("gasstate"), "name", "name",
                  9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "resolved", "resolved",
                  9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1460024745U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c16_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786048U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c16_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("abs"), "name", "name", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c16_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c16_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c16_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]I:/MATLABWORK/GTF/FunctionsLibrary/gasstate.m"), "context", "context",
                  14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mpower"), "name", "name", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c16_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c16_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("ismatrix"), "name", "name",
                  16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c16_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("power"), "name", "name", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395303306U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c16_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c16_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c16_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c16_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c16_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410786170U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c16_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("floor"), "name", "name", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c16_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c16_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c16_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_error"), "name", "name",
                  26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c16_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c16_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mpower"), "name", "name", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c16_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("sqrt"), "name", "name", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c16_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_error"), "name", "name",
                  30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c16_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286797138U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c16_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("abs"), "name", "name", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c16_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs32), "lhs", "lhs",
                  32);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
  sf_mex_destroy(&c16_rhs7);
  sf_mex_destroy(&c16_lhs7);
  sf_mex_destroy(&c16_rhs8);
  sf_mex_destroy(&c16_lhs8);
  sf_mex_destroy(&c16_rhs9);
  sf_mex_destroy(&c16_lhs9);
  sf_mex_destroy(&c16_rhs10);
  sf_mex_destroy(&c16_lhs10);
  sf_mex_destroy(&c16_rhs11);
  sf_mex_destroy(&c16_lhs11);
  sf_mex_destroy(&c16_rhs12);
  sf_mex_destroy(&c16_lhs12);
  sf_mex_destroy(&c16_rhs13);
  sf_mex_destroy(&c16_lhs13);
  sf_mex_destroy(&c16_rhs14);
  sf_mex_destroy(&c16_lhs14);
  sf_mex_destroy(&c16_rhs15);
  sf_mex_destroy(&c16_lhs15);
  sf_mex_destroy(&c16_rhs16);
  sf_mex_destroy(&c16_lhs16);
  sf_mex_destroy(&c16_rhs17);
  sf_mex_destroy(&c16_lhs17);
  sf_mex_destroy(&c16_rhs18);
  sf_mex_destroy(&c16_lhs18);
  sf_mex_destroy(&c16_rhs19);
  sf_mex_destroy(&c16_lhs19);
  sf_mex_destroy(&c16_rhs20);
  sf_mex_destroy(&c16_lhs20);
  sf_mex_destroy(&c16_rhs21);
  sf_mex_destroy(&c16_lhs21);
  sf_mex_destroy(&c16_rhs22);
  sf_mex_destroy(&c16_lhs22);
  sf_mex_destroy(&c16_rhs23);
  sf_mex_destroy(&c16_lhs23);
  sf_mex_destroy(&c16_rhs24);
  sf_mex_destroy(&c16_lhs24);
  sf_mex_destroy(&c16_rhs25);
  sf_mex_destroy(&c16_lhs25);
  sf_mex_destroy(&c16_rhs26);
  sf_mex_destroy(&c16_lhs26);
  sf_mex_destroy(&c16_rhs27);
  sf_mex_destroy(&c16_lhs27);
  sf_mex_destroy(&c16_rhs28);
  sf_mex_destroy(&c16_lhs28);
  sf_mex_destroy(&c16_rhs29);
  sf_mex_destroy(&c16_lhs29);
  sf_mex_destroy(&c16_rhs30);
  sf_mex_destroy(&c16_lhs30);
  sf_mex_destroy(&c16_rhs31);
  sf_mex_destroy(&c16_lhs31);
  sf_mex_destroy(&c16_rhs32);
  sf_mex_destroy(&c16_lhs32);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static real_T c16_abs(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance,
                      real_T c16_x)
{
  real_T c16_b_x;
  (void)chartInstance;
  c16_b_x = c16_x;
  return muDoubleScalarAbs(c16_b_x);
}

static real_T c16_mpower(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_a, real_T c16_b)
{
  real_T c16_b_a;
  real_T c16_b_b;
  real_T c16_c_a;
  real_T c16_c_b;
  real_T c16_ak;
  real_T c16_bk;
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_d_a;
  real_T c16_d_b;
  real_T c16_ar;
  real_T c16_br;
  c16_b_a = c16_a;
  c16_b_b = c16_b;
  c16_c_a = c16_b_a;
  c16_c_b = c16_b_b;
  c16_eml_scalar_eg(chartInstance);
  c16_ak = c16_c_a;
  c16_bk = c16_c_b;
  if (c16_ak < 0.0) {
    c16_x = c16_bk;
    c16_b_x = c16_x;
    c16_b_x = muDoubleScalarFloor(c16_b_x);
    if (c16_b_x != c16_bk) {
      c16_eml_error(chartInstance);
    }
  }

  c16_d_a = c16_ak;
  c16_d_b = c16_bk;
  c16_eml_scalar_eg(chartInstance);
  c16_ar = c16_d_a;
  c16_br = c16_d_b;
  return muDoubleScalarPower(c16_ar, c16_br);
}

static void c16_eml_scalar_eg(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c16_eml_error(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  int32_T c16_i0;
  static char_T c16_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c16_u[31];
  const mxArray *c16_y = NULL;
  (void)chartInstance;
  for (c16_i0 = 0; c16_i0 < 31; c16_i0++) {
    c16_u[c16_i0] = c16_cv0[c16_i0];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c16_y));
}

static real_T c16_sqrt(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_x)
{
  real_T c16_b_x;
  c16_b_x = c16_x;
  c16_b_sqrt(chartInstance, &c16_b_x);
  return c16_b_x;
}

static void c16_b_eml_error(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  int32_T c16_i1;
  static char_T c16_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c16_u[30];
  const mxArray *c16_y = NULL;
  int32_T c16_i2;
  static char_T c16_cv2[4] = { 's', 'q', 'r', 't' };

  char_T c16_b_u[4];
  const mxArray *c16_b_y = NULL;
  (void)chartInstance;
  for (c16_i1 = 0; c16_i1 < 30; c16_i1++) {
    c16_u[c16_i1] = c16_cv1[c16_i1];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c16_i2 = 0; c16_i2 < 4; c16_i2++) {
    c16_b_u[c16_i2] = c16_cv2[c16_i2];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c16_y, 14, c16_b_y));
}

static real_T c16_b_mpower(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T c16_a)
{
  real_T c16_b_a;
  real_T c16_c_a;
  real_T c16_ak;
  real_T c16_d_a;
  c16_b_a = c16_a;
  c16_c_a = c16_b_a;
  c16_eml_scalar_eg(chartInstance);
  c16_ak = c16_c_a;
  c16_d_a = c16_ak;
  c16_eml_scalar_eg(chartInstance);
  return c16_d_a * c16_d_a;
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static int32_T c16_c_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i3;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i3, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i3;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)
    chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_d_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_b_is_active_c16_GTF_EnginePath_TwoSpool, const char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_GTF_EnginePath_TwoSpool), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_GTF_EnginePath_TwoSpool);
  return c16_y;
}

static uint8_T c16_e_emlrt_marshallIn
  (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance, const mxArray
   *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sqrt(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance, real_T *c16_x)
{
  if (*c16_x < 0.0) {
    c16_b_eml_error(chartInstance);
  }

  *c16_x = muDoubleScalarSqrt(*c16_x);
}

static void init_dsm_address_info(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
  *chartInstance)
{
  chartInstance->c16_Pt8 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_Tt8 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c16_Pt_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c16_Tt_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_W_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c16_W8 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c16_V = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c16_Ma = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c16_PR_Real = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c16_Pamb = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c16_Wf = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c16_P8 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
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

void sf_c16_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2927103779U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3409133336U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2151692601U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(101066245U);
}

mxArray* sf_c16_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
mxArray *sf_c16_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ndtJuwrM91mDJr32tERleH");
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

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c16_GTF_EnginePath_TwoSpool_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c16_GTF_EnginePath_TwoSpool_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_GTF_EnginePath_TwoSpool_jit_fallback_info(void)
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

mxArray *sf_c16_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c16_GTF_EnginePath_TwoSpool_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c16_GTF_EnginePath_TwoSpool(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[14],T\"Ma\",},{M[1],M[11],T\"P8\",},{M[1],M[15],T\"PR_Real\",},{M[1],M[12],T\"Pt8\",},{M[1],M[16],T\"Tt8\",},{M[1],M[13],T\"V\",},{M[1],M[5],T\"W8\",},{M[8],M[0],T\"is_active_c16_GTF_EnginePath_TwoSpool\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_GTF_EnginePath_TwoSpool_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GTF_EnginePath_TwoSpoolMachineNumber_,
           16,
           1,
           1,
           0,
           12,
           0,
           0,
           0,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"Pt8");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Tt8");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Pt_in");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Tt_in");
          _SFD_SET_DATA_PROPS(4,1,1,0,"W_in");
          _SFD_SET_DATA_PROPS(5,2,0,1,"W8");
          _SFD_SET_DATA_PROPS(6,2,0,1,"V");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Ma");
          _SFD_SET_DATA_PROPS(8,2,0,1,"PR_Real");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Pamb");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Wf");
          _SFD_SET_DATA_PROPS(11,2,0,1,"P8");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1197);
        _SFD_CV_INIT_EML_IF(0,1,0,386,401,854,1003);
        _SFD_CV_INIT_EML_IF(0,1,1,727,733,765,804);
        _SFD_CV_INIT_EML_WHILE(0,1,0,576,594,812);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,389,401,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,730,733,-1,4);
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
        _SFD_CV_INIT_SCRIPT(1,1,5,0,0,1,0,1,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"gasstate",0,-1,1364);
        _SFD_CV_INIT_SCRIPT_IF(1,0,205,215,-1,234);
        _SFD_CV_INIT_SCRIPT_IF(1,1,235,252,-1,276);
        _SFD_CV_INIT_SCRIPT_IF(1,2,298,311,-1,339);
        _SFD_CV_INIT_SCRIPT_IF(1,3,544,558,-1,586);
        _SFD_CV_INIT_SCRIPT_IF(1,4,591,605,-1,634);
        _SFD_CV_INIT_SCRIPT_WHILE(1,0,367,408,1289);

        {
          static int caseStart[] = { 953, 846 };

          static int caseExprEnd[] = { 962, 852 };

          _SFD_CV_INIT_SCRIPT_SWITCH(1,0,816,838,1270,2,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,0,208,215,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,1,238,252,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,2,301,311,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,3,548,558,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,4,594,605,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)c16_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c16_Pt8);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c16_Tt8);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c16_Pt_in);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c16_Tt_in);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c16_W_in);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c16_W8);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c16_V);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c16_Ma);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c16_PR_Real);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c16_Pamb);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c16_Wf);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c16_P8);
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
  return "D4kpZ8WzBs3pEy9EEfFY3F";
}

static void sf_opaque_initialize_c16_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
  initialize_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  enable_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  disable_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_GTF_EnginePath_TwoSpool(void *chartInstanceVar)
{
  sf_gateway_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c16_GTF_EnginePath_TwoSpool
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c16_GTF_EnginePath_TwoSpool(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c16_GTF_EnginePath_TwoSpool(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GTF_EnginePath_TwoSpool_optimization_info();
    }

    finalize_c16_GTF_EnginePath_TwoSpool
      ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_GTF_EnginePath_TwoSpool
    ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_GTF_EnginePath_TwoSpool(SimStruct *S)
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
    initialize_params_c16_GTF_EnginePath_TwoSpool
      ((SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GTF_EnginePath_TwoSpool_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1673760396U));
  ssSetChecksum1(S,(2262079526U));
  ssSetChecksum2(S,(481939762U));
  ssSetChecksum3(S,(3481323097U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_GTF_EnginePath_TwoSpool(SimStruct *S)
{
  SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct *)utMalloc(sizeof
    (SFc16_GTF_EnginePath_TwoSpoolInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_GTF_EnginePath_TwoSpoolInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_GTF_EnginePath_TwoSpool;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_GTF_EnginePath_TwoSpool;
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

void c16_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_GTF_EnginePath_TwoSpool(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_GTF_EnginePath_TwoSpool(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_GTF_EnginePath_TwoSpool_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
