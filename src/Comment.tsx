interface CommentProps {
    name: string;
    image: string;
    comment: string;
    comments?: CommentProps[];
}


export default function Comment({ name, image, comment, comments }: CommentProps) {
    return (
        <div className='border p-4 m-2 ml-12 flex-col items-center gap-x-12 rounded-md'>
            <div className='flex justify-center items-center border gap-x-2 rounded-md w-full px-8 p-2'>
                <img
                    className='w-12 h-12 rounded-full'
                    src={image}
                    alt='User Avatar'
                />
                <h1 className='font-bold'>{name}</h1>
                <p>{comment}</p>
            </div>

            <div className="flex flex-col">
                {
                    comments && comments.map((c: CommentProps, id) => (
                        <Comment
                            name={c.name}
                            key={id}
                            image={c.image}
                            comment={c.comment}
                            comments={c.comments}
                        />
                    ))
                }
            </div>
        </div>
    )
}
