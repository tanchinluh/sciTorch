/***********************************************************************
* sciTorch - Machine and Deep Learning Module for Scilab 6
* Original work Copyright (C) 2019  Tan Chin Luh
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***********************************************************************/


#include "common.h"
//int GetImage(int nPos, Mat& new_img, void* pvApiCtx)
//int GetImage(int nPos, scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out)
int GetImage(int nPos, scilabEnv env, scilabVar* in)
{

	//SciErr sciErr;
	//int* piAddr = NULL;
	int iType = 0;
	//int iRet = 0;
	//int * dims = NULL;
	//int ndims;
	//double* pdblReal = NULL;


	iType = scilab_getType(env, in[nPos]);

	sciprint("%i", iType);


//	sciErr = getVarAddressFromPosition(pvApiCtx, nPos, &piAddr);
//	if (sciErr.iErr)
//	{
//		printError(&sciErr, 0);
//		return -1;
//	}
//
//	sciErr = getVarType(pvApiCtx, piAddr, &iType);
//	if (sciErr.iErr)
//	{
//		printError(&sciErr, 0);
//		return -1;
//	}
//
//	//sciprint("\tType: %i : ", iType);
//
//	switch (iType)
//	{
//	case sci_matrix:
//	{
//		if (isHypermatType(pvApiCtx, piAddr))
//		{
//			/////////////////////
//			// 3D Double Image //
//			/////////////////////
//			sciErr = getHypermatOfDouble(pvApiCtx, piAddr, &dims, &ndims, &pdblReal);
//			if (sciErr.iErr)
//			{
//				printError(&sciErr, 0);
//				return -1;
//			}
//			int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//			//new_img = Mat(ndims, sz2, CV_64F, pdblReal);	
//			new_img = Mat(2, sz2, CV_64FC(*(dims + 2)));
//			scidata2matdata(new_img, pdblReal);
//		}
//		else
//		{
//
//			//sciprint("2D Double Image Detected...\n");
//			int iRows = 0;
//			int iCols = 0;
//
//			/////////////////////
//			// 2D Double Image //
//			/////////////////////
//
//			sciErr = getMatrixOfDouble(pvApiCtx, piAddr, &iRows, &iCols, &pdblReal);
//			if (sciErr.iErr)
//			{
//				printError(&sciErr, 0);
//				return sciErr.iErr;
//			}
//
//			int sz2[] = { iRows,iCols };
//
//			new_img = Mat(2, sz2, CV_64F);
//			scidata2matdata(new_img, pdblReal);
//		}
//
//
//	}
//	break;
//	case sci_poly:
//		sciprint("A matrix of polynomials\n");
//		break;
//	case sci_boolean:
//	{
//		if (isHypermatType(pvApiCtx, piAddr))
//		{
//			int* piBool = NULL;
//			/////////////////////
//			// 3D Boolean Image //
//			/////////////////////
//			sciErr = getHypermatOfBoolean(pvApiCtx, piAddr, &dims, &ndims, &piBool);
//			//sciErr = getHypermatOfInteger32(pvApiCtx, piAddr, &dims, &ndims, &piBool);			
//			if (sciErr.iErr)
//			{
//				printError(&sciErr, 0);
//				return -1;
//			}
//			int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//			//new_img = Mat(ndims, sz2, CV_64F, pdblReal);	
//			//new_img = Mat(2, sz2, CV_64FC3);
//			//scidata2matdata(new_img, pdblReal);
//
//			/////////////////////
//			//int sz2[] = {iRows,iCols};
//
//			Mat new_img2;
//			new_img2 = Mat(2, sz2, CV_32SC3);
//			scidata2matdata(new_img2, piBool);
//			new_img = Mat(2, sz2, CV_8UC(*(dims + 2)));
//			new_img2.convertTo(new_img, CV_8UC(*(dims + 2)), 255);
//		}
//		else
//		{
//
//			int iRows = 0;
//			int iCols = 0;
//			int* piBool = NULL;
//			sciErr = getMatrixOfBoolean(pvApiCtx, piAddr, &iRows, &iCols, &piBool);
//			if (sciErr.iErr)
//			{
//				printError(&sciErr, 0);
//				return -1;
//			}
//			int sz2[] = { iRows,iCols };
//
//			Mat new_img2;
//			new_img2 = Mat(2, sz2, CV_32S);
//			scidata2matdata(new_img2, piBool);
//
//			new_img = Mat(2, sz2, CV_8U);
//			new_img2.convertTo(new_img, CV_8U, 255);
//		}
//
//	}
//	break;
//	case sci_sparse:
//		sciprint("A sparse matrix of doubles\n");
//		break;
//	case sci_boolean_sparse:
//		sciprint("A sparse matrix of booleans\n");
//		break;
//	case sci_matlab_sparse:
//		sciprint("A sparse matlab matrix\n");
//		break;
//	case sci_ints:
//		//sciprint("A matrix of integers\n");
//	{
//		int precision;
//		sciErr = getMatrixOfIntegerPrecision(pvApiCtx, piAddr, &precision);
//		if (sciErr.iErr)
//		{
//			printError(&sciErr, 0);
//			return sciErr.iErr;
//		}
//		//sciprint("datatype found: %i\n",precision);
//		switch (precision)
//		{
//		case SCI_INT8:
//		{
//			if (isHypermatType(pvApiCtx, piAddr))
//			{
//				//void * data = NULL;
//				char* pucData = NULL;
//
//				//sciprint("Precision : %i - SCI_UINT8\n", precision);
//				/////////////////////
//				// 3D INT8 Image //
//				/////////////////////
//				//sciErr = getHypermatOfUnsignedInteger8(pvApiCtx, piAddr, &dims, &ndims, (unsigned char**)&data);
//				sciErr = getHypermatOfInteger8(pvApiCtx, piAddr, &dims, &ndims, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return -1;
//				}
//				int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//
//				new_img = Mat(2, sz2, CV_8SC(*(dims + 2)));
//				scidata2matdata(new_img, pucData);
//			}
//			else
//			{
//
//				int iRows = 0;
//				int iCols = 0;
//				char* pucData = NULL;
//
//				//sciprint("Precision : %i - SCI_UINT8\n", precision);
//				/////////////////////
//				// 2D UINT8 Image //
//				/////////////////////
//				sciErr = getMatrixOfInteger8(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return sciErr.iErr;
//				}
//				int sz2[] = { iRows,iCols };
//
//				new_img = Mat(2, sz2, CV_8S);
//				scidata2matdata(new_img, pucData);
//			}
//		}
//		break;
//		case SCI_UINT8:
//		{
//
//			if (isHypermatType(pvApiCtx, piAddr))
//			{
//				//void * data = NULL;
//				unsigned char* pucData = NULL;
//
//				//sciprint("Precision : %i - SCI_UINT8\n", precision);
//				/////////////////////
//				// 3D UINT8 Image //
//				/////////////////////
//				sciErr = getHypermatOfUnsignedInteger8(pvApiCtx, piAddr, &dims, &ndims, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return -1;
//				}
//				int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//				new_img = Mat(2, sz2, CV_8UC(*(dims + 2)));
//				scidata2matdata(new_img, pucData);
//			}
//			else
//			{
//				int iRows = 0;
//				int iCols = 0;
//				unsigned char* pucData = NULL;
//
//				/////////////////////
//				// 2D UINT8 Image //
//				/////////////////////
//				sciErr = getMatrixOfUnsignedInteger8(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return sciErr.iErr;
//				}
//				int sz2[] = { iRows,iCols };
//
//				new_img = Mat(2, sz2, CV_8U);
//				scidata2matdata(new_img, pucData);
//			}
//
//		}
//		break;
//		case SCI_INT16:
//		{
//			if (isHypermatType(pvApiCtx, piAddr))
//			{
//				//void * data = NULL;
//				short* pucData = NULL;
//
//				//sciprint("Precision : %i - SCI_UINT16\n", precision);
//				/////////////////////
//				// 3D INT16 Image //
//				/////////////////////
//				//sciErr = getHypermatOfUnsignedInteger8(pvApiCtx, piAddr, &dims, &ndims, (unsigned char**)&data);
//				sciErr = getHypermatOfInteger16(pvApiCtx, piAddr, &dims, &ndims, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return -1;
//				}
//				int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//				//new_img = Mat(2, sz2, CV_8UC3, pucData);	
//
//				//int sz2[] = {iCols,iRows};
//
//				new_img = Mat(2, sz2, CV_16SC(*(dims + 2)));
//				scidata2matdata(new_img, pucData);
//			}
//			else
//			{
//
//				int iRows = 0;
//				int iCols = 0;
//				short* pucData = NULL;
//
//				/////////////////////
//				// 2D UINT16 Image //
//				/////////////////////
//				sciErr = getMatrixOfInteger16(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return sciErr.iErr;
//				}
//				int sz2[] = { iRows,iCols };
//
//				new_img = Mat(2, sz2, CV_16S);
//				scidata2matdata(new_img, pucData);
//			}
//
//		}
//		break;
//
//		case SCI_UINT16:
//		{
//			if (isHypermatType(pvApiCtx, piAddr))
//			{
//				unsigned short* pucData = NULL;
//
//				//sciprint("Precision : %i - SCI_UINT16\n", precision);
//				/////////////////////
//				// 3D UINT16 Image //
//				/////////////////////
//				//sciErr = getHypermatOfUnsignedInteger8(pvApiCtx, piAddr, &dims, &ndims, (unsigned char**)&data);
//				sciErr = getHypermatOfUnsignedInteger16(pvApiCtx, piAddr, &dims, &ndims, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return -1;
//				}
//				int sz2[] = { *dims, *(dims + 1), *(dims + 2) };
//				//new_img = Mat(2, sz2, CV_8UC3, pucData);	
//
//				//int sz2[] = {iCols,iRows};
//
//				new_img = Mat(2, sz2, CV_16UC(*(dims + 2)));
//				scidata2matdata(new_img, pucData);
//			}
//			else
//			{
//
//				int iRows = 0;
//				int iCols = 0;
//				unsigned short* pucData = NULL;
//
//				/////////////////////
//				// 2D UINT16 Image //
//				/////////////////////
//				sciErr = getMatrixOfUnsignedInteger16(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return sciErr.iErr;
//				}
//				int sz2[] = { iRows,iCols };
//
//				new_img = Mat(2, sz2, CV_16U);
//				scidata2matdata(new_img, pucData);
//			}
//
//		}
//		break;
//
//		case SCI_INT32:
//		{
//			if (isHypermatType(pvApiCtx, piAddr))
//			{
//				//sciErr = getHypermatOfInteger32(pvApiCtx, piAddr, &dims, &ndims, (int*)&data);
//				//if(sciErr.iErr)
//				//{
//				//	printError(&sciErr, 0);
//				//	return sciErr.iErr;
//				//}
//				sciprint("Precision : %i - SCI_INT32\n", precision);
//				break;
//			}
//			else
//			{
//				int iRows = 0;
//				int iCols = 0;
//				int* pucData = NULL;
//
//				/////////////////////
//				// 2D INT32 Image //
//				/////////////////////
//				sciErr = getMatrixOfInteger32(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
//				if (sciErr.iErr)
//				{
//					printError(&sciErr, 0);
//					return sciErr.iErr;
//				}
//				int sz2[] = { iRows,iCols };
//
//				new_img = Mat(2, sz2, CV_32S);
//				scidata2matdata(new_img, pucData);
//			}
//
//		}
//		break;
//		case SCI_UINT32:
//			//sciErr = getHypermatOfUnsignedInteger32(pvApiCtx, piAddr, &dims, &ndims, (unsigned int*)&data);
//			//if(sciErr.iErr)
//			//{
//			//	printError(&sciErr, 0);
//			//	return sciErr.iErr;
//			//}
//			sciprint("Precision : %i - SCI_UINT32\n", precision);
//			break;
//		}
//	}
//
//	break;
//
//	case sci_pointer:
//		sciprint("A pointer\n");
//		break;
//	default:
//		sciprint("Unknown type !\n"); // Should never happen
//	}
//
//
//	/*sciprint("-----------------------\n");
//	sciprint("Get Image Properties...\n");
//	sciprint("-----------------------\n");
//	sciprint("dims : %i\n",new_img.dims);
//	sciprint("rows  : %i\n",new_img.rows );
//	sciprint("cols  : %i\n",new_img.cols );
//	sciprint("channels  : %i\n",new_img.channels() );
//	sciprint("dims  : %i\t %i\t %i\t\n",*dims, *(dims+1), *(dims+2));
//	sciprint("depth  : %i\n",new_img.depth());*/
//
//
//
	return 0;
}


//
////int scidata2matdata(Mat &pImage, unsigned char* pMatData)
//int scidata2matdata(Mat &pImage, void* pMatData)
//{
//	//int row, col, ch;
//	int rows, cols;
//	long nCount = 0;
//	int nBytes;
//	SciErr sciErr;
//	unsigned char * pDst = NULL;
//	unsigned char * pSrc = NULL;
//	//sciprint("pucData : %d \t %d \t %c \t %c \t\n", pMatData, &pMatData, pMatData, &pMatData);
//	//if (pImage == NULL || pMatData == NULL)
//	//	return FALSE;
//	//sciprint("Check Point 1\n");
//
//
//	////////////////
//	//pDst = (unsigned char*)pImage.data;
//	//pSrc = (unsigned char*)pMatData;
//	///*how many bytes per pixel per channel*/
//	//nBytes = pImage.elemSize1();
//	//for(ch = 0; ch < pImage.channels() ; ch++) //the order of IplImage is BGR
//	//	for(col =0; col < pImage.size().width; col++)
//	//		for(row = 0; row < pImage.size().height; row++)
//	//		{
//	//			memcpy(pDst + pImage.step*row + (col*pImage.channels() + (pImage.channels()-ch-1))*nBytes, pSrc+nCount, nBytes );
//	//			nCount += nBytes;
//	//		}
//	//////////////////
//
//	///////////////////////////////////////
//	//pImage = pImage.t();
//	pImage = pImage.t();
//	pDst = (unsigned char*)(pImage.data);
//	pSrc = (unsigned char*)pMatData;
//	rows = pImage.rows;
//	cols = pImage.cols;
//
//	nBytes = pImage.elemSize1();
//	//nBytes = 1;	
//	//sciprint("nBytes : %i\n",nBytes);
//	if (pImage.channels() == 1)
//	{
//		memcpy(pDst, pSrc, rows*cols*nBytes);
//	}
//	else if (pImage.channels() == 3)
//	{
//		vector<Mat> ch1; // B, G, R channels
//		split(pImage, ch1);
//
//		//memcpy(pDst, ch1[2].ptr(), rows*cols*nBytes);
//		//memcpy(pDst+rows*cols, ch1[1].ptr(), rows*cols*nBytes);
//		//memcpy(pDst+2*rows*cols, ch1[0].ptr(), rows*cols*nBytes);
//		memcpy(ch1[2].ptr(), pSrc, rows*cols*nBytes);
//		memcpy(ch1[1].ptr(), pSrc + rows*cols*nBytes, rows*cols*nBytes);
//		memcpy(ch1[0].ptr(), pSrc + 2 * rows*cols*nBytes, rows*cols*nBytes);
//		//ch1[2].data = pSrc;
//		//ch1[1].data = pSrc+rows*cols;
//		//ch1[0].data = pSrc+2*rows*cols;
//		merge(ch1, pImage);
//	}
//
//	// 20190309 : Add to write multidimension images
//	else if (pImage.channels() == 4)
//	{
//		vector<Mat> ch1; // B, G, R channels
//		split(pImage, ch1);
//
//
//		memcpy(ch1[2].ptr(), pSrc + 0 * rows*cols*nBytes, rows*cols*nBytes);
//		memcpy(ch1[1].ptr(), pSrc + 1 * rows*cols*nBytes, rows*cols*nBytes);
//		memcpy(ch1[0].ptr(), pSrc + 2 * rows*cols*nBytes, rows*cols*nBytes);
//		memcpy(ch1[3].ptr(), pSrc + 3 * rows*cols*nBytes, rows*cols*nBytes);
//
//		//ch1[2].data = pSrc;
//		//ch1[1].data = pSrc+rows*cols;
//		//ch1[0].data = pSrc+2*rows*cols;
//		merge(ch1, pImage);
//	}
//	else
//	{
//		printError(&sciErr, 0);
//	}
//
//
//
//	pImage = pImage.t();
//
//	//////////////////////
//	//int ch,col;
//	//sciprint("This line show pDst\n");
//	//for(ch = 0; ch < rows ; ch++) 
//	//{
//	//	for(col =0; col < cols; col++)		
//	//	{
//	//		//sciprint("%i\t%i\t%i\n",&pDst,pDst,*pDst);
//	//		//*pDst++;
//	//		sciprint("%d\t",*(pDst+ch*pImage.step+col)); //
//	//		//sciprint("%f\t",pDst[ch*pImage.step+col]);
//	//	}
//	//	sciprint("\n");
//	//}
//	//////////////////////
//	return 0;
//}
