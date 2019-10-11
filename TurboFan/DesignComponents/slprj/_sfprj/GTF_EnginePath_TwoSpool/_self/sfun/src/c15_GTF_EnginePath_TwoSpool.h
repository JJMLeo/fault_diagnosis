#ifndef __c15_GTF_EnginePath_TwoSpool_h__
#define __c15_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc15_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_GTF_EnginePath_TwoSpool;
  real_T *c15_T_in;
  real_T *c15_P_in;
  real_T *c15_Ma;
  real_T *c15_Pt_out;
  real_T *c15_Tt_out;
} SFc15_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc15_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c15_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
