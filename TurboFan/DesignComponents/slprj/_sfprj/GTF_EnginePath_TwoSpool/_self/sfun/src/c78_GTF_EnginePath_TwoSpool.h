#ifndef __c78_GTF_EnginePath_TwoSpool_h__
#define __c78_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc78_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc78_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c78_sfEvent;
  boolean_T c78_isStable;
  boolean_T c78_doneDoubleBufferReInit;
  uint8_T c78_is_active_c78_GTF_EnginePath_TwoSpool;
  real_T *c78_f;
  real_T *c78_DHT;
  real_T *c78_EffHPT;
  real_T *c78_Tt44;
  real_T *c78_Tt41;
  real_T *c78_h5;
  real_T *c78_Sfcn5;
  real_T *c78_PR;
  real_T *c78_Sfcn41;
} SFc78_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc78_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c78_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c78_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c78_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
