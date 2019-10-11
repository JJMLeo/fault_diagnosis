#ifndef __c63_TSE_Path_h__
#define __c63_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc63_TSE_PathInstanceStruct
#define typedef_SFc63_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c63_sfEvent;
  boolean_T c63_isStable;
  boolean_T c63_doneDoubleBufferReInit;
  uint8_T c63_is_active_c63_TSE_Path;
  real_T *c63_f;
  real_T *c63_PRGT;
  real_T *c63_EFGT;
  real_T *c63_T5s;
  real_T *c63_T41s;
  real_T *c63_h5;
  real_T *c63_Sfcn5;
  real_T *c63_Sfcn41;
  real_T *c63_DHT_T;
} SFc63_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc63_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c63_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c63_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c63_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
