#ifndef __c76_GTF_EnginePath_TwoSpool_h__
#define __c76_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc76_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc76_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c76_sfEvent;
  boolean_T c76_isStable;
  boolean_T c76_doneDoubleBufferReInit;
  uint8_T c76_is_active_c76_GTF_EnginePath_TwoSpool;
  real_T *c76_Tt4;
  real_T *c76_W4;
  real_T *c76_WcoolHPT;
  real_T *c76_Tt3;
  real_T *c76_Tt41;
  real_T *c76_Wf;
  real_T *c76_Sfcn41;
} SFc76_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc76_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c76_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c76_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c76_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
