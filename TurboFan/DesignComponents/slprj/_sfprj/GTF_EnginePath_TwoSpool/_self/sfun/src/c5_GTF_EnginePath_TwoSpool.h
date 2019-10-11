#ifndef __c5_GTF_EnginePath_TwoSpool_h__
#define __c5_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc5_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_GTF_EnginePath_TwoSpool;
  real_T *c5_Pt18;
  real_T *c5_Tt18;
  real_T *c5_Pt13;
  real_T *c5_Tt13;
  real_T *c5_W18;
  real_T *c5_V;
  real_T *c5_Ma;
  real_T *c5_PR_Real;
  real_T *c5_Pamb;
  real_T *c5_P18;
} SFc5_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc5_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c5_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
