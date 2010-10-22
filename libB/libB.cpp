#include "libB.h"

#include <itkTransformFileReader.h>

B::B()
{
  itk::TransformFileReader::Pointer tfr = itk::TransformFileReader::New();

  this->x = 1;
}

