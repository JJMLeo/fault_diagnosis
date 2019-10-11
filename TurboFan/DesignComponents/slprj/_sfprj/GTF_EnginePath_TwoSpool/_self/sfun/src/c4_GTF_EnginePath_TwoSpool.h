#ifndef __c4_GTF_EnginePath_TwoSpool_h__
#define __c4_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc4_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_GTF_EnginePath_TwoSpool;
  real_T *c4_W24;
  real_T *c4_Tt_Z2;
  real_T *c4_Tt_Z3;
  real_T *c4_PR;
  real_T *c4_Tt3;
  real_T *c4_Eff;
  real_T *c4_Tt24;
  real_T *c4_Load_Compr;
  real_T *c4_Deflate;
} SFc4_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc4_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c4_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
