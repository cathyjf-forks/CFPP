/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        CFPP-ReadStream.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFReadStreamRef wrapper
 */

#include <CF++.h>

namespace CF
{
    ReadStream::ReadStream( std::string path )
    {
        CF::URL url;
        
        url = CF::URL::FileSystemURL( path );
        
        this->_cfObject = CFReadStreamCreateWithFile( static_cast< CFAllocatorRef >( NULL ), url );
    }
    
    ReadStream::ReadStream( const ReadStream & value )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value._cfObject ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    ReadStream::ReadStream( CFTypeRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    ReadStream::ReadStream( CFReadStreamRef value )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
    }
    
    #ifdef CFPP_HAS_CPP11
    ReadStream::ReadStream( ReadStream && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
    }
    #endif
    
    ReadStream::~ReadStream( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    ReadStream & ReadStream::operator = ( ReadStream value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    ReadStream & ReadStream::operator = ( CFTypeRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    ReadStream & ReadStream::operator = ( CFReadStreamRef value )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFReadStreamRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->_cfObject = NULL;
        }
        
        return *( this );
    }
    
    CFTypeID ReadStream::GetTypeID( void ) const
    {
        return CFReadStreamGetTypeID();
    }
    
    CFTypeRef ReadStream::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    void swap( ReadStream & v1, ReadStream & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}