#ifndef __c9_GTF_EnginePath_TwoSpool_h__
#define __c9_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc9_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_GTF_EnginePath_TwoSpool;
  real_T *c9_f;
  real_T *c9_DHT;
  real_T *c9_EffLPT;
  real_T *c9_Tt5;
  real_T *c9_Tt45;
  real_T *c9_h5;
  real_T *c9_Sfcn5;
  real_T *c9_PR;
  real_T *c9_Sfcn45;
} SFc9_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc9_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c9_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
